

//�Ω���� Multiplication.h ���� multip_2num �禡�����յ{���]testbench�^�C�Ӵ��յ{���q�L�N���P����ƹ�ǻ��� multip_2num �禡�A���ˬd���^�ȬO�_�����������ƭ��n�A�Ӵ��� multip_2num �禡�����T�ʡC
#include <iostream>
#include "Multiplication.h"//�H�K�b�{�����ϥμ��Y��"Multiplication.h"�������w�q�M�ŧi�C

using namespace std;

int main(int argc, char *argv[])
{
	int i, j;
	int pass = 1; //�Ω�O�����լO�_�q�L�A��l�Ȭ� 1�A��ܳq�L�C
	int n32Multip; //�Ω�s�x multip_2num �禡����^�ȡA�Y��ƭ��n�C

	cout << ">> Start test!" << endl;//�ϥ� cout �N�}�l���ժ��T����X��׺ݡC

	for(i = 1; i < 10; i++) {//�����~��U�@�����j��A������է��Ҧ���ƹ�C
		cout << "------------------------" << endl;
		for(j = 1; j < 10; j++) {
			multip_2num(i, j, &n32Multip);//�b�j�餺���A�ϥ� multip_2num �禡�p�� i �M j �����n�A�ñN���G�s�x�b n32Multip ���C

			cout << i << " * " << j << " = " << n32Multip << endl;//�ϥ� cout �N�p�⵲�G��X��׺ݡA�]�A i�Bj �M n32Multip ���ȡC
			if(n32Multip != (i * j)) {//�ˬd�p�⵲�G�O�_���� i * j�A�p�G������A�h�N pass �]�m�� 0�A��ܴ��ե��q�L�C
				pass = 0;
			}
		}
	}
	cout << "------------------------" << endl;//���է�����A��X���j�u�M���յ��G�T���C

	if(!pass) {
		cout << ">> Test failed!" << endl;//�̲��ˬd pass ���ȡA�p�G�� 0�A��ܴ��ե��q�L�A��X���ե��Ѫ��T���A�ê�^���~�X 1�C�p�G pass ���M�� 1�A��ܴ��ճq�L�A��X���ճq�L���T���A�ê�^���T�X 0�C
		return 1;
	}

	cout << ">> Test passed!" << endl;
	cout << "------------------------" << endl;
	return 0;
}


/*cout << ">> Start test!" << endl;

cout�Gcout �O C++ �зǵ{���w�����зǿ�X�y�A�Ω�V�׺ݵ��f��X��T�C

<<�G�o�O��X�y�B��l�A�Ω�N�k�������e��X�쥪�����y���C�b�o�ӱ��p�U�A���N�r�� ">> Start test!" ��X�� cout �y���C

">> Start test!"�G�o�O�n��X���r��A���]�t�F�T�����e�C

endl�Gendl �O C++ �зǵ{���w�����зǿ�X�����Ÿ��A����ܴ���è�s��X�w�İϡC�� endl �Q�ϥήɡA���|�N���e�����e��X��׺ݡA�M�ᴫ��C�o���U��T�O�T���Q�ߧY��ܦb�׺ݵ��f���C*/