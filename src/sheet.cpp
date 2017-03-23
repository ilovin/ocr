#include "sheet.h"

vector<vector<WordBox<BOX_POINT>>> NormSheet()
{
	WordBox<BOX_POINT> Single;
	vector<WordBox<BOX_POINT>> temSheet;
	vector<vector<WordBox<BOX_POINT>> > Sheet;
	//int nItem = 21;// 21 tatol items
	
	 
	string Item;
	string Cont;
	int row, col;
	double wid[3], hei;
	BOX_POINT OriP, TotP;
	vector<BOX_POINT> square,NormSqu;
	double origin_x = 124.0, origin_y = 191.0,
		ReWid = 1312.0 - origin_x, // total width
		ReHei = 963.0 - origin_y;  //total height

	OriP = BOX_POINT(origin_x, origin_y);
	TotP = BOX_POINT(ReWid, ReHei);

	//initialize the detail items
	
	Item = "机打代码/机打号码/机器编号";
	row = 0;
	col = 0;
	// set the normalized square
	square.push_back(BOX_POINT(124.0, 191.0) - OriP);	
	square.push_back(BOX_POINT(124.0, 376.0) - OriP);	
	square.push_back(BOX_POINT(286.0, 377.0) - OriP);	
	square.push_back(BOX_POINT(286.0, 193.0) - OriP);
	NormSqu=VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col,ENG,ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 0;
	col = 1;
	// set the normalized square
	square.push_back(BOX_POINT(286.0, 193.0) - OriP);
	square.push_back(BOX_POINT(286.0, 376.0) - OriP);
	square.push_back(BOX_POINT(643.0, 377.0) - OriP);
	square.push_back(BOX_POINT(643.0, 193.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);

		
	Item = "税控码";
	row = 0;
	col = 2;
	// set the normalized square
	square.push_back(BOX_POINT(643.0, 193.0) - OriP);
	square.push_back(BOX_POINT(643.0, 376.0) - OriP);
	square.push_back(BOX_POINT(689.0, 377.0) - OriP);
	square.push_back(BOX_POINT(689.0, 192.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 0;
	col = 3;
	// set the normalized square
	square.push_back(BOX_POINT(689.0, 192.0) - OriP);
	square.push_back(BOX_POINT(689.0, 376.0) - OriP);
	square.push_back(BOX_POINT(1312.0, 377.0) - OriP);
	square.push_back(BOX_POINT(1312.0, 193.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);

	Sheet.push_back(temSheet); // the first row
	temSheet.clear();

	Item = "购买方名称及身份证号码/组织机构代码";
	row = 1;
	col = 0;
	// set the normalized square
	square.push_back(BOX_POINT(124.0, 376.0) - OriP);
	square.push_back(BOX_POINT(124.0, 455.0) - OriP);
	square.push_back(BOX_POINT(286.0, 455.0) - OriP);
	square.push_back(BOX_POINT(286.0, 377.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 1;
	col = 1;
	// set the normalized square
	square.push_back(BOX_POINT(286.0, 377.0) - OriP);
	square.push_back(BOX_POINT(286.0, 455.0) - OriP);
	square.push_back(BOX_POINT(689.0, 455.0) - OriP);
	square.push_back(BOX_POINT(689.0, 376.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);

	
	Item = "纳税人识别号";
	row = 1;
	col = 2;
	// set the normalized square
	square.push_back(BOX_POINT(689, 376.0) - OriP);
	square.push_back(BOX_POINT(689, 455.0) - OriP);
	square.push_back(BOX_POINT(956.0, 455.0) - OriP);
	square.push_back(BOX_POINT(956.0, 377.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 1;
	col = 3;
	// set the normalized square
	square.push_back(BOX_POINT(956.0, 376.0) - OriP);
	square.push_back(BOX_POINT(956.0, 455.0) - OriP);
	square.push_back(BOX_POINT(1312.0, 455.0) - OriP);
	square.push_back(BOX_POINT(1312.0, 377.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);

	Sheet.push_back(temSheet); // the 2 row
	temSheet.clear();

	Item = "车辆类型";
	row = 2;
	col = 0;
	// set the normalized square
	square.push_back(BOX_POINT(124.0, 455.0) - OriP);
	square.push_back(BOX_POINT(124.0, 507.0) - OriP);
	square.push_back(BOX_POINT(286.0, 507.0) - OriP);
	square.push_back(BOX_POINT(286.0, 455.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 2;
	col = 1;
	// set the normalized square
	square.push_back(BOX_POINT(286.0, 455.0) - OriP);
	square.push_back(BOX_POINT(286.0, 507.0) - OriP);
	square.push_back(BOX_POINT(643.0, 507.0) - OriP);
	square.push_back(BOX_POINT(643.0, 455.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);

	
	Item = "厂牌型号";
	row = 2;
	col = 2;
	// set the normalized square
	square.push_back(BOX_POINT(642.0, 455.0) - OriP);
	square.push_back(BOX_POINT(642.0, 507.0) - OriP);
	square.push_back(BOX_POINT(747.0, 507.0) - OriP);
	square.push_back(BOX_POINT(747.0, 455.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 2;
	col = 3;
	// set the normalized square
	square.push_back(BOX_POINT(747.0, 455.0) - OriP);
	square.push_back(BOX_POINT(747.0, 507.0) - OriP);
	square.push_back(BOX_POINT(1006.0, 507.0) - OriP);
	square.push_back(BOX_POINT(1006.0, 455.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);


	Item = "产地";
	row = 2; 
	col = 4;
	// set the normalized square
	square.push_back(BOX_POINT(1006.0, 455.0) - OriP);
	square.push_back(BOX_POINT(1006.0, 507.0) - OriP);
	square.push_back(BOX_POINT(1102.0, 507.0) - OriP);
	square.push_back(BOX_POINT(1102.0, 455.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 2;
	col = 5;
	// set the normalized square
	square.push_back(BOX_POINT(1102.0, 455.0) - OriP);
	square.push_back(BOX_POINT(1102.0, 507.0) - OriP);
	square.push_back(BOX_POINT(1312.0, 507.0) - OriP);
	square.push_back(BOX_POINT(1312.0, 455.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);

	Sheet.push_back(temSheet); // the 3 row
	temSheet.clear();

	Item = "合格证号";
	row = 3;
	col = 0;
	// set the normalized square
	square.push_back(BOX_POINT(124.0, 507.0) - OriP);
	square.push_back(BOX_POINT(124.0, 564.0) - OriP);
	square.push_back(BOX_POINT(286.0, 564.0) - OriP);
	square.push_back(BOX_POINT(286.0, 507.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 3;
	col = 1;
	// set the normalized square
	square.push_back(BOX_POINT(286.0, 507.0) - OriP);
	square.push_back(BOX_POINT(286.0, 564.0) - OriP);
	square.push_back(BOX_POINT(642.0, 564.0) - OriP);
	square.push_back(BOX_POINT(643.0, 507.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);


	Item = "Empty";
	row = 3;
	col = 2;
	// set the normalized square
	square.push_back(BOX_POINT(642.0, 507.0) - OriP);
	square.push_back(BOX_POINT(642.0, 564.0) - OriP);
	square.push_back(BOX_POINT(789.0, 564.0) - OriP);
	square.push_back(BOX_POINT(789.0, 507.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 3;
	col = 3;
	// set the normalized square
	square.push_back(BOX_POINT(789.0, 507.0) - OriP);
	square.push_back(BOX_POINT(789.0, 564.0) - OriP);
	square.push_back(BOX_POINT(1312.0, 564.0) - OriP);
	square.push_back(BOX_POINT(1312.0, 507.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);

	Sheet.push_back(temSheet);  //the 4th row
	temSheet.clear();

	Item = "发动机号码";
	row = 4;
	col = 0;
	// set the normalized square
	square.push_back(BOX_POINT(124.0, 564.0) - OriP);
	square.push_back(BOX_POINT(124.0, 617.0) - OriP);
	square.push_back(BOX_POINT(286.0, 617.0) - OriP);
	square.push_back(BOX_POINT(286.0, 564.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 4;
	col = 1;
	// set the normalized square
	square.push_back(BOX_POINT(286.0, 564.0) - OriP);
	square.push_back(BOX_POINT(286.0, 617.0) - OriP);
	square.push_back(BOX_POINT(691.0, 617.0) - OriP);
	square.push_back(BOX_POINT(691.0, 564.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);

	Item = "车辆识别代号/车架号码";
	row = 4;
	col = 2;
	// set the normalized square
	square.push_back(BOX_POINT(691.0, 564.0) - OriP);
	square.push_back(BOX_POINT(691.0, 617.0) - OriP);
	square.push_back(BOX_POINT(934.0, 617.0) - OriP);
	square.push_back(BOX_POINT(934.0, 564.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 4;
	col = 3;
	// set the normalized square
	square.push_back(BOX_POINT(934.0, 564.0) - OriP);
	square.push_back(BOX_POINT(934.0, 617.0) - OriP);
	square.push_back(BOX_POINT(1312.0, 617.0) - OriP);
	square.push_back(BOX_POINT(1312.0, 564.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);

	Sheet.push_back(temSheet); // the 5 row
	temSheet.clear();

	Item = "价税合计";
	row = 5;
	col = 0;
	// set the normalized square
	square.push_back(BOX_POINT(124.0, 617.0) - OriP);
	square.push_back(BOX_POINT(124.0, 674.0) - OriP);
	square.push_back(BOX_POINT(286.0, 674.0) - OriP);
	square.push_back(BOX_POINT(286.0, 617.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 5;
	col = 1;
	// set the normalized square
	square.push_back(BOX_POINT(286.0, 617.0) - OriP);
	square.push_back(BOX_POINT(286.0, 674.0) - OriP);
	square.push_back(BOX_POINT(934.0, 674.0) - OriP);
	square.push_back(BOX_POINT(934.0, 617.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);


	Item = "价税小写";
	row = 5;
	col = 2;
	// set the normalized square
	square.push_back(BOX_POINT(934.0, 617.0) - OriP);
	square.push_back(BOX_POINT(934.0, 674.0) - OriP);
	square.push_back(BOX_POINT(1063.0, 674.0) - OriP);
	square.push_back(BOX_POINT(1063.0, 617.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 5;
	col = 3;
	// set the normalized square
	square.push_back(BOX_POINT(1063.0, 618.0) - OriP);
	square.push_back(BOX_POINT(1063.0, 674.0) - OriP);
	square.push_back(BOX_POINT(1312.0, 674.0) - OriP);
	square.push_back(BOX_POINT(1312.0, 617.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);

	Sheet.push_back(temSheet); // the 6 row
	temSheet.clear();

	Item = "销货单位名称";
	row = 6;
	col = 0;
	// set the normalized square
	square.push_back(BOX_POINT(124.0, 674.0) - OriP);
	square.push_back(BOX_POINT(124.0, 728.0) - OriP);
	square.push_back(BOX_POINT(286.0, 728.0) - OriP);
	square.push_back(BOX_POINT(286.0, 674.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 6;
	col = 1;
	// set the normalized square
	square.push_back(BOX_POINT(286.0, 674.0) - OriP);
	square.push_back(BOX_POINT(286.0, 728.0) - OriP);
	square.push_back(BOX_POINT(911.0, 728.0) - OriP);
	square.push_back(BOX_POINT(911.0, 674.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);


	Item = "电话";
	row = 6;
	col = 2;
	// set the normalized square
	square.push_back(BOX_POINT(911.0, 674.0) - OriP);
	square.push_back(BOX_POINT(911.0, 728.0) - OriP);
	square.push_back(BOX_POINT(971.0, 728.0) - OriP);
	square.push_back(BOX_POINT(971.0, 674.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 6;
	col = 3;
	// set the normalized square
	square.push_back(BOX_POINT(971.0, 674.0) - OriP);
	square.push_back(BOX_POINT(971.0, 728.0) - OriP);
	square.push_back(BOX_POINT(1312.0, 728.0) - OriP);
	square.push_back(BOX_POINT(1312.0, 674.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);

	Sheet.push_back(temSheet); // the 7 row
	temSheet.clear();

	Item = "纳税人识别号";
	row = 7;
	col = 0;
	// set the normalized square
	square.push_back(BOX_POINT(124.0, 728.0) - OriP);
	square.push_back(BOX_POINT(124.0, 780.0) - OriP);
	square.push_back(BOX_POINT(286.0, 780.0) - OriP);
	square.push_back(BOX_POINT(286.0, 728.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 7;
	col = 1;
	// set the normalized square
	square.push_back(BOX_POINT(286.0, 728.0) - OriP);
	square.push_back(BOX_POINT(286.0, 780.0) - OriP);
	square.push_back(BOX_POINT(911.0, 780.0) - OriP);
	square.push_back(BOX_POINT(911.0, 728.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);


	Item = "账号";
	row = 7;
	col = 2;
	// set the normalized square
	square.push_back(BOX_POINT(911.0, 728.0) - OriP);
	square.push_back(BOX_POINT(911.0, 780.0) - OriP);
	square.push_back(BOX_POINT(971.0, 780.0) - OriP);
	square.push_back(BOX_POINT(971.0, 728.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 7;
	col = 3;
	// set the normalized square
	square.push_back(BOX_POINT(971.0, 728.0) - OriP);
	square.push_back(BOX_POINT(971.0, 780.0) - OriP);
	square.push_back(BOX_POINT(1312.0, 780.0) - OriP);
	square.push_back(BOX_POINT(1312.0, 728.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);

	Sheet.push_back(temSheet); // the 8 row
	temSheet.clear();

	Item = "地址";
	row = 8;
	col = 0;
	// set the normalized square
	square.push_back(BOX_POINT(124.0, 780.0) - OriP);
	square.push_back(BOX_POINT(124.0, 838.0) - OriP);
	square.push_back(BOX_POINT(286.0, 838.0) - OriP);
	square.push_back(BOX_POINT(286.0, 780.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 8;
	col = 1;
	// set the normalized square
	square.push_back(BOX_POINT(286.0, 780.0) - OriP);
	square.push_back(BOX_POINT(286.0, 838.0) - OriP);
	square.push_back(BOX_POINT(754.0, 838.0) - OriP);
	square.push_back(BOX_POINT(754.0, 780.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);

	Item = "开户银行";
	row = 8;
	col = 2;
	// set the normalized square
	square.push_back(BOX_POINT(754.0, 780.0) - OriP);
	square.push_back(BOX_POINT(754.0, 838.0) - OriP);
	square.push_back(BOX_POINT(854.0, 838.0) - OriP);
	square.push_back(BOX_POINT(854.0, 780.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 8;
	col = 3;
	// set the normalized square
	square.push_back(BOX_POINT(854.0, 780.0) - OriP);
	square.push_back(BOX_POINT(854.0, 838.0) - OriP);
	square.push_back(BOX_POINT(1312.0, 838.0) - OriP);
	square.push_back(BOX_POINT(1312.0, 780.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);

	Sheet.push_back(temSheet); // the 9 row
	temSheet.clear();

	Item = "增值税税率";
	row = 9;
	col = 0;
	// set the normalized square
	square.push_back(BOX_POINT(124.0, 838.0) - OriP);
	square.push_back(BOX_POINT(124.0, 909.0) - OriP);
	square.push_back(BOX_POINT(286.0, 909.0) - OriP);
	square.push_back(BOX_POINT(286.0, 838.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 9;
	col = 1;
	// set the normalized square
	square.push_back(BOX_POINT(286.0, 838.0) - OriP);
	square.push_back(BOX_POINT(286.0, 909.0) - OriP);
	square.push_back(BOX_POINT(438.0, 909.0) - OriP);
	square.push_back(BOX_POINT(438.0, 838.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);


	Item = "增值税税额";
	row = 9;
	col = 2;
	// set the normalized square
	square.push_back(BOX_POINT(438.0, 838.0) - OriP);
	square.push_back(BOX_POINT(438.0, 909.0) - OriP);
	square.push_back(BOX_POINT(533.0, 909.0) - OriP);
	square.push_back(BOX_POINT(533.0, 838.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 9;
	col = 3;
	// set the normalized square
	square.push_back(BOX_POINT(286.0, 838.0) - OriP);
	square.push_back(BOX_POINT(286.0, 909.0) - OriP);
	square.push_back(BOX_POINT(438.0, 909.0) - OriP);
	square.push_back(BOX_POINT(438.0, 838.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);


	Item = "主管税务机关及代码";
	row = 9;
	col = 4;
	// set the normalized square
	square.push_back(BOX_POINT(783.0, 838.0) - OriP);
	square.push_back(BOX_POINT(783.0, 909.0) - OriP);
	square.push_back(BOX_POINT(913.0, 909.0) - OriP);
	square.push_back(BOX_POINT(913.0, 838.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 9;
	col = 5;
	// set the normalized square
	square.push_back(BOX_POINT(913.0, 838.0) - OriP);
	square.push_back(BOX_POINT(913.0, 909.0) - OriP);
	square.push_back(BOX_POINT(1312.0, 909.0) - OriP);
	square.push_back(BOX_POINT(1312.0, 838.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);

	Sheet.push_back(temSheet); // the 10 row
	temSheet.clear();


	Item = "不含税价";
	row = 10;
	col = 0;
	// set the normalized square
	square.push_back(BOX_POINT(124.0, 909.0) - OriP);
	square.push_back(BOX_POINT(124.0, 963.0) - OriP);
	square.push_back(BOX_POINT(286.0, 963.0) - OriP);
	square.push_back(BOX_POINT(286.0, 909.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 10;
	col = 1;
	// set the normalized square
	square.push_back(BOX_POINT(355.0, 909.0) - OriP);
	square.push_back(BOX_POINT(355.0, 963.0) - OriP);
	square.push_back(BOX_POINT(567.0, 963.0) - OriP);
	square.push_back(BOX_POINT(567.0, 909.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);


	Item = "Empty";
	row = 10;
	col = 2;
	// set the normalized square
	square.push_back(BOX_POINT(567.0, 909.0) - OriP);
	square.push_back(BOX_POINT(567.0, 963.0) - OriP);
	square.push_back(BOX_POINT(714.0, 963.0) - OriP);
	square.push_back(BOX_POINT(714.0, 909.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 10;
	col = 3;
	// set the normalized square
	square.push_back(BOX_POINT(714.0, 909.0) - OriP);
	square.push_back(BOX_POINT(714.0, 963.0) - OriP);
	square.push_back(BOX_POINT(1120.0, 963.0) - OriP);
	square.push_back(BOX_POINT(1120.0, 909.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);

	
	Item = "限乘人数";
	row = 10;
	col = 4;
	// set the normalized square
	square.push_back(BOX_POINT(1120.0, 909.0) - OriP);
	square.push_back(BOX_POINT(1120.0, 963.0) - OriP);
	square.push_back(BOX_POINT(1218.0, 963.0) - OriP);
	square.push_back(BOX_POINT(1218.0, 909.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 10;
	col = 5;
	// set the normalized square
	square.push_back(BOX_POINT(1218.0, 909.0) - OriP);
	square.push_back(BOX_POINT(1218.0, 963.0) - OriP);
	square.push_back(BOX_POINT(1312.0, 963.0) - OriP);
	square.push_back(BOX_POINT(1312.0, 909.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);

	Sheet.push_back(temSheet); // the 11 row
	temSheet.clear();


	Item = "Empty"; //开票人
	row = 11;
	col = 0;
	// set the normalized square
	square.push_back(BOX_POINT(567.0, 963.0) - OriP);
	square.push_back(BOX_POINT(567.0, 1002.0) - OriP);
	square.push_back(BOX_POINT(700.0, 1002.0) - OriP);
	square.push_back(BOX_POINT(700.0, 963.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 11;
	col = 1;
	// set the normalized square
	square.push_back(BOX_POINT(700.0, 963.0) - OriP);
	square.push_back(BOX_POINT(700.0, 1002.0) - OriP);
	square.push_back(BOX_POINT(996.0, 1002.0) - OriP);
	square.push_back(BOX_POINT(996.0, 963.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);

	Sheet.push_back(temSheet); // the 12 row
	temSheet.clear();

	Item = "Empty";  //开票日期
	row = 12;
	col = 0;
	// set the normalized square
	square.push_back(BOX_POINT(124.0, 146.0) - OriP);
	square.push_back(BOX_POINT(124.0, 191.0) - OriP);
	square.push_back(BOX_POINT(230.0, 191.0) - OriP);
	square.push_back(BOX_POINT(230.0, 146.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Item, row, col, ENG, ITEM);
	temSheet.push_back(Single);

	Cont = "Empty";
	row = 12;
	col = 1;
	// set the normalized square
	square.push_back(BOX_POINT(230.0, 146.0) - OriP);
	square.push_back(BOX_POINT(230.0, 191.0) - OriP);
	square.push_back(BOX_POINT(450.0, 191.0) - OriP);
	square.push_back(BOX_POINT(450.0, 146.0) - OriP);
	NormSqu = VecDevPoint(square, TotP);
	square.clear();

	Single.boxInit(NormSqu);
	Single.setWordBox(Cont, row, col, ENG, CONTENT);
	temSheet.push_back(Single);

	Sheet.push_back(temSheet); // the first row
	temSheet.clear();

	

	return Sheet;
}

/*
"Box": is the biggest box on the sheet, sorted by anticlockwise
NormSheet: the normalized sheet
Sheet: correspond with the input image
 create boxes that circumscribe "item" or "content"
 */
void SheetImage(vector<vector<WordBox<BOX_POINT>>>& normSheet, vector<vector<WordBox<Point>>>& Sheet, vector<cv::Point> Box)
{
	int numRow = (int)normSheet.size(), numCol,temWid,temHei;
	int widBox = Box[TOP_RIGHT].x - Box[TOP_LEFT].x, heiBox= Box[DOWN_LEFT].y - Box[TOP_LEFT].y;
	cv::Point pointRec = Point(widBox, heiBox);
	vector<BOX_POINT> squ;
	vector<Point> psqu;
	WordBox<cv::Point> temWord;
	vector<WordBox<cv::Point> > temBox;
	 
	Sheet.clear();
	//Initialize Sheet
	for (int k = 0; numRow > k; k++)
	{
		temBox.clear();
		for (int j = 0; normSheet[k].size() > j; j++)
		{
			squ = VecMultiPoint(normSheet[k][j].getSquare(), pointRec);
			psqu = vecPointfd2Point(squ);
			temWord.boxInit(psqu);
			temWord.setWordBox(normSheet[k][j].getWords(), normSheet[k][j].getRow(), normSheet[k][j].getColum(), normSheet[k][j].getCharacter(), normSheet[k][j].getItemCont());
			temBox.push_back(temWord);
		}
		Sheet.push_back(temBox);

	}
		


}

 
/*
//find four points in order to do perspective transformation
//perspImage: the result of the perspective transformation
//boxFind: whether the biggest box is found, 1 is found, -1 is not found
//foundSquare: the found biggest box
*/
int ExtractBill(const cv::Mat& srcImage, cv::Mat& perspImage, vector<BaseBox<>>& SortSquare, vector<cv::Point> &foundSquare)
{
	int sameP = 5,// the points are on the same line
		minFlag = 10,
		onflag, online;
	int nSqu = (int)SortSquare.size(), 
		boxFind;// whether the biggest box is found
				//1:found; -1: not found
	int persp_width, persp_height;
	double  maxAng = 1.0 * CV_PI / 180.0;
	vector<cv::Point2d> Pre, Cur, vecP;

	double lenV[3], angV[3];
	vector<BOX_POINT> pointList(4);
	vector<BOX_POINT> dstPointList;// = { BOX_POINT(0, 0), BOX_POINT(paper_width, 0),BOX_POINT(paper_width, paper_height), BOX_POINT(0, paper_height) };


	for (int i = 0; i < nSqu; i++)
	{
		Pre.clear();
		onflag = 0; //the number of squares that the left vertical line are on the square "i's" left vertical line
					//the chosen points
		Pre.push_back(SortSquare[i].getSquare(TOP_LEFT));
		Pre.push_back(SortSquare[i].getSquare(DOWN_LEFT));
		for (int j = i + 1; j < nSqu; j++)
		{
			if ((SortSquare[j].getArea() / SortSquare[i].getArea()) < 0.2)
			{
				Cur.clear();
				//the detected points
				Cur.push_back(SortSquare[j].getSquare(TOP_LEFT));
				Cur.push_back(SortSquare[j].getSquare(DOWN_LEFT));

				// if three points are on the same line, the vectors should be parallel
				online = 0;  //the three points are on the same  line
				for (int k = 0; k < 2; k++)
				{
					vecP.clear();
					//the first vector
					vecP.push_back(Pre[1] - Cur[k]);
					lenV[0] = sqrt(vecP[0].x*vecP[0].x + vecP[0].y*vecP[0].y);//length
																			  // the second
					vecP.push_back(Cur[k] - Pre[0]);
					lenV[1] = sqrt(vecP[1].x*vecP[1].x + vecP[1].y*vecP[1].y);//length
																			  //the third
					vecP.push_back(Pre[1] - Pre[0]);  //the long vetor
					lenV[2] = sqrt(vecP[2].x*vecP[2].x + vecP[2].y*vecP[2].y);//length
					if (lenV[2] < 1.0) lenV[2] = 1;

					if ((lenV[0] < sameP) || (lenV[1] < sameP))
					{
						online++;  //the three points are on the same  line
					}
					else
					{
						angV[0] = acos(fabs((vecP[0].x*vecP[1].x + vecP[0].y*vecP[1].y) / (lenV[0] * lenV[1])));//0,1
						angV[1] = acos(fabs((vecP[0].x*vecP[2].x + vecP[0].y*vecP[2].y) / (lenV[0] * lenV[2])));//0,2
						angV[2] = acos(fabs((vecP[2].x*vecP[1].x + vecP[2].y*vecP[1].y) / (lenV[2] * lenV[1])));//1,2
						if ((angV[0] < maxAng) && (angV[1] < maxAng) && (angV[2] < maxAng))// the vectors are parellel
						{
							online++;
						}

					}
				}
				if (online == 2) onflag++;
			}
		}

		if (onflag > minFlag)// the biggest box is found
		{
			//find the right-up point of the biggest box
			double sdx[4], sdy[4], sdist[4],
				recDis[4],// the height of the square whose distance between the biggest square is the minimum
				mindist[4] = { -1.0,-1.0,-1.0,-1.0 };
			//vector<cv::Point> pointRU(4);// the found biggest box
			BaseBox<> foundBox;
			for (int k = i + 1; k < nSqu; k++)
			{
				if ((SortSquare[k].getArea() / SortSquare[i].getArea()) < 0.5)
				{
					for (int m = 0; m < 4; m++)//anticlockwise
					{
						sdx[m] = SortSquare[k].getSquare(m).x - SortSquare[i].getSquare(m).x;
						sdy[m] = SortSquare[k].getSquare(m).y - SortSquare[i].getSquare(m).y;
						sdist[m] = sqrt(sdx[m]*sdx[m] + sdy[m]*sdy[m]);
						if (mindist[m] == (-1.0))
						{
							mindist[m] = sdist[m];// find the minmum distance
							foundSquare[m] = SortSquare[k].getSquare(m);
							recDis[m] = SortSquare[k].getHeight()/2.0;// get the limitation
						}
						else if (sdist[m] < mindist[m])
						{
							mindist[m] = sdist[m];
							foundSquare[m] = SortSquare[k].getSquare(m);
							recDis[m] = SortSquare[k].getHeight();
						}
					}					

				}
			}
			foundBox.boxInit(foundSquare);

			persp_height = foundBox.getHeight();//MAXBOXHEIGHT;//
			persp_width = foundBox.getWidth();//MAXBOXHEIGHT;//
			//int rc = 50;
			//circle(srcImage, pointRU, rc, CvScalar(255, 0, 0),7);
			//MyImageShow(srcImage);			
			//cvWaitKey();

			//clockwise
			for (int m = 0; m < 4; m++)
			{
				if (m == TOP_LEFT)
				{
					if (mindist[m] < (0.3*recDis[m]))
					{
						pointList[0] = foundSquare[TOP_LEFT];
					}
					else
					{
						pointList[0] = SortSquare[i].getSquare(TOP_LEFT);
					}
				}
				if (m == TOP_RIGHT)
				{
					if (mindist[m] < (0.8 * recDis[m]))
					{
						pointList[1] = foundSquare[TOP_RIGHT];
					}
					else
					{
						pointList[1] = SortSquare[i].getSquare(TOP_RIGHT);
					}
				}
				if (m == DOWN_RIGHT)
				{
					if (mindist[m] < (0.7*recDis[m]))
					{
						pointList[2] = foundSquare[DOWN_RIGHT];
					}
					else
					{
						pointList[2] = SortSquare[i].getSquare(DOWN_RIGHT);
					}
				}
				if (m == DOWN_LEFT)
				{
					if (mindist[m] < (0.7*recDis[m]))
					{
						pointList[3] = foundSquare[DOWN_LEFT];
					}
					else
					{
						pointList[3] = SortSquare[i].getSquare(DOWN_LEFT);
					}
				}
			}

			//pointList[0] = SortSquare[i].getSquare(TOP_LEFT);
			//pointList[1] = SortSquare[i].getSquare(TOP_RIGHT);
			//pointList[2] = SortSquare[i].getSquare(DOWN_RIGHT);
			//pointList[3] = SortSquare[i].getSquare(DOWN_LEFT);

			//cv::Mat dst_img = image.clone();
			dstPointList = { Point(0, 0), Point(persp_width, 0),Point(persp_width, persp_height), Point(0, persp_height) };
			cv::Mat trans = cv::getPerspectiveTransform(pointList, dstPointList);
			cv::warpPerspective(srcImage, perspImage, trans, cv::Size(persp_width, persp_height));
			//MyImgShow("perspective", perspImage);
			// delete the squares that before the "i"th square
			/*if (i > 0)
			{
				vector<BaseBox<>>::iterator begSq, endSq;
				begSq = SortSquare.begin();
				endSq = begSq + i;
				SortSquare.erase(begSq, endSq);

			}
			else if (i == 0)
			{
				vector<BaseBox<>>::iterator begSq;
				begSq = SortSquare.begin();
				SortSquare.erase(begSq);
			}*/
			boxFind = 1;
			break;
			
		}
		else boxFind = -1;
	}
	 
	return boxFind;
}



