#include"MoveFrame.h"

 MoveFrame::MoveFrame():Pawn(0), Rook(1), Knight(2), Bishop(3),Queen(4), King(5)
{
	 turnWay = 0;
	 MoveOverX = 0;
	 MoveOverY = 0;
}
MoveFrame::~MoveFrame()
{

}

//���g���C�p�̏�����
void MoveFrame::NewFrameData()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			FrameData[i][j] = -1;
			//Frame�\���̔z��̏�����
			Frame[i][j].Moveflag = false;
			Frame[i][j].MoveX = 0;
			Frame[i][j].MoveY = 0;
			Frame[i][j].FrameName = 0;
			
			if (i < 4)
			{
				Frame[i][j].playerColor = false;
			}
			else
			{
				Frame[i][j].playerColor = true;
			}

			//�e�������W�@�܂����̏ꏊ�̃f�[�^���e��f�[�^�Ƃ��Ċi�[
			//�|�[��
			if (i == 1 || i == 6)
			{
				FrameData[i][j] = Pawn;//�S�̓I�ɂ݂��z��
				Frame[i][j].FrameName = Pawn;
			}
			//���[�N
			else if((i == 0 && j == 0) || (i == 0 && j == 7) ||
				(i == 7 && j == 0) || (i == 7 && j == 7))
			{
				FrameData[i][j] = Rook;
				Frame[i][j].FrameName = Rook;
			}
			//�i�C�g
			else if ((i == 0 && j == 1) || (i == 0 && j == 6) ||
				(i == 7 && j == 1) || (i == 7 && j == 6))
			{
				FrameData[i][j] = Knight;
				Frame[i][j].FrameName = Knight;
			}
			//�r�V���b�v
			else if ((i == 0 && j == 2) || (i == 0 && j == 5) ||
				(i == 7 && j == 2) || (i == 7 && j == 5))
			{
				FrameData[i][j] = Bishop;
				Frame[i][j].FrameName = Bishop;
			}
			//�N�C�[��
			else if((i == 0 && j == 4) ||(i == 7 && j == 4))
			{
				FrameData[i][j] = Queen;
				Frame[i][j].FrameName = Queen;
			}
			//�L���O
			else if ((i == 0 && j == 3) || (i == 7 && j == 3))
			{
				FrameData[i][j] = King;
				Frame[i][j].FrameName = King;
			}
			
				
			
			//�ړ��ł���ꏊ�̏�����
			Move[i][j] = false;
		}
	}
}
//---------------------------------------------------------------------------------------------
//�e��̈ړ��ł���ꏊ��ݒ� //�܂�����ȑ���Ȃ�
void MoveFrame::BahaviorPawn(bool turn ,int x,int y)
{
	if (turn != true)
	{
		turnWay = 1;
	}
	else
	{
		turnWay = -1;
	}
	//���ʓ���
	if (Frame[y][x].Moveflag == true)
	{
		if (FrameData[y + turnWay][x] == -1)
		{
			//������ꏊ��ݒ�
			Move[y + turnWay][x] = true;
		}
	}
	else
	{
		for (int i = 1; i <= 2; i++)
		{
			if (FrameData[y + (turnWay * i)][x] == -1)
			{
				Move[y + (turnWay * i)][x] = true;
			}
		}
	}
	//�΂ߎ��悤�Ɍ�쐬�ӏ�
}
//���[�N�@���ꏈ��������
void MoveFrame::BahaviorRook(bool turn,int x, int y)
{
	//���[�N�̂�����ꏊ��ݒ�
	for (int i = 1; i < 8; i++)
	{
		//�c�ړ�
		if (Move[y + i - 1][x] != false|| i == 1 && y + i < 8
			&& FrameData[y + i][x] == -1)
		{
			Move[y + i][x] = true;
		}
		if (Move[y - i + 1][x] != false || i == 1 && y - i >= 0
			&& FrameData[y - i][x] == -1)
		{
			Move[y - i][x] = true;
		}
		for (int j = 1; j < 8; j++)
		{
			//���ړ�
			if (Move[y][x + j - 1] != false || j == 1 && x + j < 8
				&& FrameData[y][x + j] == -1)
			{
				Move[y][x + j] = true;
			}
			if (Move[y][x - j + 1] != false || j == 1 && x - j >= 0
				&& FrameData[y][x - j] == -1)
			{
				Move[y][x - j] = true;
			}
		}
	}
}
void MoveFrame::BahaviorKnight(bool turn, int x, int y)
{

}
void MoveFrame::BahaviorBishop(bool turn, int x, int y)
{
	//�r�V���b�v�̂�����ꏊ��ݒ� ����@�E��̏�����m�F
	for (int i = 1; i < 8; i++)
	{
		for (int j = 1; j < 8; j++)
		{
			//���ړ�
			if (Move[y][x + j - 1] != false || j == 1 && x + j < 8
				&& FrameData[y][x + j] == -1)
			{
				Move[y][x + j] = true;
			}
			if (Move[y][x - j + 1] != false || j == 1 && x - j >= 0
				&& FrameData[y][x - j] == -1)
			{
				Move[y][x - j] = true;
			}
			//�΂߈ړ�
			if (Move[y - i + 1][x - j + 1] != false || j == 1 || i == 1
				&& y - i >= 0 && x - j >= 0 && FrameData[y - i][x - j] == -1)
			{
				Move[y - i][x - j] = true;
			}
			if (Move[y - i + 1][x + j - 1] != false || j == 1 || i == 1
				&& y - i >= 0 && x + j < 8 && FrameData[y - i][x + j] == -1)
			{
				Move[y - i][x + j] = true;
			}
			if (Move[y + i - 1][x - j + 1] != false || j == 1 || i == 1
				&& y + i < 8 && x - j >= 0 && FrameData[y + i][x - j] == -1)
			{
				Move[y + i][x - j] = true;
			}
			if (Move[y + i - 1][x + j - 1] != false || j == 1 || i == 1
				&& y + i < 8 && x + j < 8 && FrameData[y + i][x + j] == -1)
			{
				Move[y + i][x + j] = true;
			}
		}
	}
}
void MoveFrame::BahaviorQueen(bool turn, int x, int y)
{
	for (int i = 1; i < 8; i++)
	{
		//�c�ړ�
		if (Move[y + i - 1][x] != false || i == 1 && y + i < 8
			&& FrameData[y + i][x] == -1)
		{
			Move[y + i][x] = true;
		}
		if (Move[y - i + 1][x] != false || i == 1 && y - i >= 0
			&& FrameData[y - i][x] == -1)
		{
			Move[y - i][x] = true;
		}
		for (int j = 1; j < 8; j++)
		{
			if (Move[y - i + 1][x - j + 1] != false || j == 1 || i == 1
				&& y - i >= 0 && x - j >= 0 && FrameData[y - i][x - j] == -1)
			{
				Move[y - i][x - j] = true;
			}
			if (Move[y - i + 1][x + j - 1] != false || j == 1 || i == 1
				&& y - i >= 0 && x + j < 8 && FrameData[y - i][x + j] == -1)
			{
				Move[y - i][x + j] = true;
			}
			if (Move[y + i - 1][x - j + 1] != false || j == 1 || i == 1
				&& y + i < 8 && x - j >= 0 && FrameData[y + i][x - j] == -1)
			{
				Move[y + i][x - j] = true;
			}
			if (Move[y + i - 1][x + j - 1] != false || j == 1 || i == 1
				&& y + i < 8 && x + j < 8 && FrameData[y + i][x + j] == -1)
			{
				Move[y + i][x + j] = true;
			}
		}
	}
}
void MoveFrame::BahaviorKing(bool turn, int x, int y)
{
	//�c
	if (FrameData[y + 1][x] == -1 && y + 1 < 8 )
	{
		Move[y + 1][x]= true;
	}
	if (FrameData[y - 1][x] == -1 && y - 1 >= 0)
	{
		Move[y - 1][x] = true;
	}
	//��
	if (FrameData[y][x - 1] == -1 && x - 1 >= 0)
	{
		Move[y][x - 1] = true;
	}
	if (FrameData[y][x + 1] == -1 && x + 1 < 8)
	{
		Move[y][x + 1] = true;
	}
	//�΂߁@���ォ��E��̏�
	if (FrameData[y - 1][x - 1] == -1 && y - 1 >= 0 && x - 1 >= 0)
	{
		Move[y - 1][x - 1] = true;
	}
	if (FrameData[y - 1][x + 1] == -1 && y - 1 >= 0 && x + 1 < 8 )
	{
		Move[y - 1][x + 1] = true;
	}
	if (FrameData[y + 1][x - 1] == -1 && y - 1 < 8 && x - 1 >= 0)
	{
		Move[y + 1][x - 1] = true;
	
	}
	if (FrameData[y + 1][x + 1] == -1 && y - 1 < 8 && x + 1 < 8)
	{
		Move[y + 1][x + 1] = true;
	}
}
//�������ꏊ�̃f�[�^�̊m�F
void MoveFrame::CheckFrame(bool turn,int x, int y)
{
	if (Frame[y][x].playerColor == turn)
	{
		MoveRelease();
		switch (Frame[y][x].FrameName)
		{
			case 0:
				BahaviorPawn(turn, x, y);
				break;
			case 1:
				BahaviorRook(turn, x, y);
				break;
			case 2:
				BahaviorKnight(turn, x, y);
				break;
			case 3:
				BahaviorBishop(turn, x, y);
				break;
			case 4:
				BahaviorQueen(turn, x, y);
				break;
			case 5:
				BahaviorKing(turn, x, y);
				break;
		}
	}
}
void MoveFrame::MoveRelease()
{
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			Move[y][x] = false;
		}
	}
}
