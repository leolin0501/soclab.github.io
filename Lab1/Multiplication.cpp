
#include "Multiplication.h" //�H�K�b�{�����ϥμ��Y��"Multiplication.h"�������w�q�M�ŧi

void multip_2num(int32_t n32In1, int32_t n32In2, int32_t* pn32ResOut) //���������32���� (n32In1 �M n32In2) �@����J�A�ñ����@�ӫ��V32���ƪ����w (pn32ResOut) �@����X�C
{

//#pragma HLS INTERFACE ���O�A���̥Ω�w�q���f�ݩʡC
//#pragma HLS�G�o�O Vivado HLS �u��䴩�����ܩʫ��O���}�l�C
//INTERFACE�G�o�������w�F�o�ӫ��O�O�Ψӳ]�m�禡�������ݩʡC
#pragma HLS INTERFACE s_axilite port=pn32ResOut //�o�ӫ��O���w pn32ResOut �ѼƥΨӶǻ��@��32���ƪ����G�A�@�� AXI Lite (�@�صw���w)���f���@�����A�o�O�@�إΩ�X�ݥ~���w�骺�зǱ��f�C
#pragma HLS INTERFACE s_axilite port=n32In2 //�o��ӫ��O���w n32In2 �M n32In1 �ѼƥΨӱ�����J����ƭȡA�]�@�� AXI Lite ���f���@�����C
#pragma HLS INTERFACE s_axilite port=n32In1//�o��{���X�����ӿ�J��� n32In1 �M n32In2 �����k�B��A�M��N���G�s�x�b���w pn32ResOut ���V����m�C


//�U���o��O�Ω���w�禡������H���������]�w�A�S�O�O�Ω󱱨�w��[�t�����}�l�M����C
//"ap_ctrl_none"�Oxilinx���O�d�r���A���O�i�DVivado HLS���ͦ��}�l�M����w��[�t���������޿�C�p�G�bsynthesis�ɻݭn�w��[�t���A����ݭn�o�Ǳ���H���ӾA��a�}�l�M����w��B��C�p�G�S���o�Ǳ���H���A�i��|�ɭP�w��[�t���L�k���T�Ұʩΰ���A�q�ӾɭP���~�C
//Vivado HLS�i��|�ھګ��O���̿����Y�ͦ��w���޿�C�p�G���� ap_ctrl_none�A�i��|�v�T����O���̿����Y�A�ɭP���~�C
//�]C simulation�BCsynthesis�ɭn���ѡAcosimulation�A�ѵ��ѡC
//port=return ���� port �O�@�ӦX�k���ѧO�Ÿ��A�Ω���w�A�Q�n�w�諸�禡�ѼơA�� return �h�O�禡����^�ȡC�o�O Vivado HLS �����@�ر`���Ϊk�A�Ω���ܧA�Q�n�t�m�������ݩʬO�P�禡����^�Ȭ������C
#pragma HLS INTERFACE ap_ctrl_none port=return 



	*pn32ResOut = n32In1 * n32In2;

	return;
}


//�̿����Y�G�w�餸��Ϋ��O�������ۤ����Y
//1.�ƾڨ̿����Y�G�o�ب̿����Y�o�ͦb��@�Ӥ���ݭn�ϥΥt�@�Ӥ��󪺿�X�ƾڮɡC
//2.����̿����Y�G�o�ب̿����Y�P�w�骺����y�{�����C��@�Ӥ��󪺾ާ@����t�@�Ӥ��󪺱���H���α���R�O���v�T��