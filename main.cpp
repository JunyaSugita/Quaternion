#include "DxLib.h"
#include "Quaternion.h"

// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "LE2A_10_スギタ_ジュンヤ: タイトル";

// ウィンドウ横幅
const int WIN_WIDTH = 600;

// ウィンドウ縦幅
const int WIN_HEIGHT = 400;

void DrawFormatString(float x, float y, Quaternion q);

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlibの初期化
	if (DxLib_Init() == -1) {
		return -1;
	}

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースデータの変数宣言と読み込み


	// ゲームループで使う変数の宣言
	Quaternion* qua = new Quaternion();
	Matrix4* mat4 = new Matrix4();

	Quaternion rotation0 = qua->MakeAxisAngle({ 0.71f,0.71f,0.0f }, 0.3f);
	Quaternion rotation1 = { -rotation0.x,-rotation0.y,-rotation0.z, -rotation0.w };

	Quaternion interpolate0 = qua->Slerp(rotation0, rotation1, 0.0f);
	Quaternion interpolate1 = qua->Slerp(rotation0, rotation1, 0.3f);
	Quaternion interpolate2 = qua->Slerp(rotation0, rotation1, 0.5f);
	Quaternion interpolate3 = qua->Slerp(rotation0, rotation1, 0.7f);
	Quaternion interpolate4 = qua->Slerp(rotation0, rotation1, 1.0f);

	// 最新のキーボード情報用
	char keys[256] = { 0 };

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = { 0 };

	// ゲームループ
	while (true) {
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		for (int i = 0; i < 256; ++i)
		{
			oldkeys[i] = keys[i];
		}

		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処理
		DrawFormatString(0, 0, interpolate0);
		DrawFormatString(0, 20, interpolate1);
		DrawFormatString(0, 40, interpolate2);
		DrawFormatString(0, 60, interpolate3);
		DrawFormatString(0, 80, interpolate4);

		// 描画処理

		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1) {
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}

void DrawFormatString(float x, float y, Quaternion q) {
	DrawFormatString(x, y, GetColor(255, 255, 255), "%.2f, %.2f, %.2f, %.2f\n", q.x, q.y, q.z, q.w);
}