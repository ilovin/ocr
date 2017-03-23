#pragma once

#include <mutex>
#include <condition_variable>
#include <deque>

template <typename T,template<typename,typename=std::allocator<T>> class  Container = std::deque>
class BlockingQueue
{
private:
	std::mutex              d_mutex;
	std::condition_variable d_condition;
	// std::deque<T>          d_queue;
	Container<T>            d_queue;
public:
    BlockingQueue(std::mutex &m_m,std::condition_variable &m_cv,
            std::deque<T> &m_q):d_mutex(m_m),d_condition(m_cv),
            d_queue(m_q){}
    BlockingQueue(){}
	void push(T const& value){
		{
		    std::unique_lock<std::mutex> lock(this->d_mutex);
		    d_queue.push_front(value);
		}
		this->d_condition.notify_one();
	}
	T pop(){
		std::unique_lock<std::mutex> lock(this->d_mutex);
		this->d_condition.wait(lock,[this]{return !this->d_queue.empty();});
		T rc(std::move(this->d_queue.back()));
		this->d_queue.pop_back();
		return rc;
	}
	bool tryPop(T& v,std::chrono::milliseconds dur){
		std::unique_lock<std::mutex> lock(this->d_mutex);
        if(!this->d_condition.wait_for(lock,dur,
                [this]{return !this->d_queue.empty();}))
            return false;
        v = std::move(this->d_queue.back());
        this->d_queue.pop_back();
        return true;
	}
	int size(){
        std::unique_lock<std::mutex> lock(this->d_mutex);
        return d_queue.size();
	}
};

