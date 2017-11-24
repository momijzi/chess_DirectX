#pragma once


class MoveFrame
{
private:
	const int Pawn;		//雑魚
	const int Rook;		//ルーク
	const int Knight;	//馬鹿
	const int Bishop;	//坊主（僧）
	const int Queen;	//全能　本当の王
	const int King;		//無能な王

	int turnWay;		//ターンに応じて動く方向を設定

	int MoveOverX;
	int MoveOverY;

	int FrameData[8][8];
	bool Move[8][8];

public:
	MoveFrame();
	~MoveFrame();

	
	//駒の構造体
	struct Frame
	{
		//移動
		int MoveX;
		int MoveY;
		//初期に動いたかどうか
		bool Moveflag;
		//配列内で名前設定
		int FrameName;
		//プレイヤーの色
		bool playerColor;
	};

	Frame Frame[8][8];

	void NewFrameData();
	//各駒の動ける場所を取得
	void BahaviorPawn(bool turn, int x, int y);
	void BahaviorRook(bool turn, int x, int y);
	void BahaviorKnight(bool turn, int x, int y);
	void BahaviorBishop(bool turn, int x, int y);
	void BahaviorQueen(bool turn, int x, int y);
	void BahaviorKing(bool turn, int x, int y);
	void CheckFrame(bool turn,int x, int y);
	
	bool GetFramePlayer(int x, int y) { return Frame[y][x].playerColor;}
	int GetFrameData(int x, int y) { return FrameData[y][x];}
	bool GetMoveFrame(int x,int y) { return Move[y][x]; }
	void MoveRelease();
};
