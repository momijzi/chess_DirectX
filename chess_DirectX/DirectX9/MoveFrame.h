#pragma once


class MoveFrame
{
private:
	const int Pawn;		//�G��
	const int Rook;		//���[�N
	const int Knight;	//�n��
	const int Bishop;	//�V��i�m�j
	const int Queen;	//�S�\�@�{���̉�
	const int King;		//���\�ȉ�

	int turnWay;		//�^�[���ɉ����ē���������ݒ�

	int MoveOverX;
	int MoveOverY;

	int FrameData[8][8];
	bool Move[8][8];

public:
	MoveFrame();
	~MoveFrame();

	
	//��̍\����
	struct Frame
	{
		//�ړ�
		int MoveX;
		int MoveY;
		//�����ɓ��������ǂ���
		bool Moveflag;
		//�z����Ŗ��O�ݒ�
		int FrameName;
		//�v���C���[�̐F
		bool playerColor;
	};

	Frame Frame[8][8];

	void NewFrameData();
	//�e��̓�����ꏊ���擾
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
