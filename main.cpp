#include "DxLib.h"
#include "Quaternion.h"

// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char TITLE[] = "LE2A_10_�X�M�^_�W������: �^�C�g��";

// �E�B���h�E����
const int WIN_WIDTH = 600;

// �E�B���h�E�c��
const int WIN_HEIGHT = 400;

void DrawFormatString(float x, float y, Quaternion q);

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlib�̏�����
	if (DxLib_Init() == -1) {
		return -1;
	}

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���


	// �Q�[�����[�v�Ŏg���ϐ��̐錾
	Quaternion* qua = new Quaternion();
	Matrix4* mat4 = new Matrix4();

	Quaternion rotation0 = qua->MakeAxisAngle({ 0.71f,0.71f,0.0f }, 0.3f);
	Quaternion rotation1 = { -rotation0.x,-rotation0.y,-rotation0.z, -rotation0.w };

	Quaternion interpolate0 = qua->Slerp(rotation0, rotation1, 0.0f);
	Quaternion interpolate1 = qua->Slerp(rotation0, rotation1, 0.3f);
	Quaternion interpolate2 = qua->Slerp(rotation0, rotation1, 0.5f);
	Quaternion interpolate3 = qua->Slerp(rotation0, rotation1, 0.7f);
	Quaternion interpolate4 = qua->Slerp(rotation0, rotation1, 1.0f);

	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = { 0 };

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = { 0 };

	// �Q�[�����[�v
	while (true) {
		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		for (int i = 0; i < 256; ++i)
		{
			oldkeys[i] = keys[i];
		}

		// �ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);

		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		// �X�V����
		DrawFormatString(0, 0, interpolate0);
		DrawFormatString(0, 20, interpolate1);
		DrawFormatString(0, 40, interpolate2);
		DrawFormatString(0, 60, interpolate3);
		DrawFormatString(0, 80, interpolate4);

		// �`�揈��

		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1) {
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}

void DrawFormatString(float x, float y, Quaternion q) {
	DrawFormatString(x, y, GetColor(255, 255, 255), "%.2f, %.2f, %.2f, %.2f\n", q.x, q.y, q.z, q.w);
}