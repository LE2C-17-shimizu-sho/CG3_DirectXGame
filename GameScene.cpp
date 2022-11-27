#include "GameScene.h"
#include <cassert>

using namespace DirectX;

GameScene::GameScene()
{
}


GameScene::~GameScene()
{
	delete spriteBG;
	delete particleMan;
	delete object3d;

	//スプライトの開放
	delete sprite1;
	delete sprite2;
}

void GameScene::Initialize(DirectXCommon* dxCommon, Input* input)
{
	// nullptrチェック
	assert(dxCommon);
	assert(input);

	this->dxCommon = dxCommon;
	this->input = input;

	// デバッグテキスト用テクスチャ読み込み
	Sprite::LoadTexture(debugTextTexNumber, L"Resources/debugfont.png");
	// デバッグテキスト初期化
	debugText.Initialize(debugTextTexNumber);

	// テクスチャ読み込み
	Sprite::LoadTexture(1, L"Resources/background.png");

	// 背景スプライト生成
	spriteBG = Sprite::Create(1, { 0.0f,0.0f });
	// 3Dオブジェクト生成
	object3d = Object3d::Create();
	object3d->Update();
	//object3d->BillBoardUpdate();
	// パーティクル生成
	particleMan = ParticleManager::Create();
	particleMan->Update();

	//テクスチャ2番に読み込み
	Sprite::LoadTexture(2, L"Resources/texture.png");
	Sprite::LoadTexture(2, L"Resources/effect.png");

	//座標{0,0}に、テクスチャ2番のスプライトを生成
	sprite1 = Sprite::Create(2, { 0,0 });
	//座標{500,0}に、テクスチャ2番のスプライトを生成
	sprite2 = Sprite::Create(2, { 500,500 },{1,0,0,1},{0,0},false,true);

	texture = Sprite::Create(2, { 200,200 });
}

void GameScene::Update()
{
	switch (scene_)
	{
	case GameScene::Scene::BillboardON:
		// オブジェクト移動
		if (input->PushKey(DIK_UP) || input->PushKey(DIK_DOWN) || input->PushKey(DIK_RIGHT) || input->PushKey(DIK_LEFT))
		{
			// 現在の座標を取得
			XMFLOAT3 position = object3d->GetPosition();

			position = { 100.0f,100.0f,100.0f };

			//// 移動後の座標を計算
			//if (input->PushKey(DIK_UP)) { position.y += 1.0f; }
			//else if (input->PushKey(DIK_DOWN)) { position.y -= 1.0f; }
			//if (input->PushKey(DIK_RIGHT)) { position.x += 1.0f; }
			//else if (input->PushKey(DIK_LEFT)) { position.x -= 1.0f; }

			// 座標の変更を反映
			object3d->SetPosition(position);
		}

		// カメラ移動
		if (input->PushKey(DIK_W) || input->PushKey(DIK_S) || input->PushKey(DIK_D) || input->PushKey(DIK_A))
		{
			if (input->PushKey(DIK_W)) { Object3d::CameraMoveEyeVector({ 0.0f,+1.0f,0.0f }); }
			else if (input->PushKey(DIK_S)) { Object3d::CameraMoveEyeVector({ 0.0f,-1.0f,0.0f }); }
			if (input->PushKey(DIK_D)) { Object3d::CameraMoveEyeVector({ +1.0f,0.0f,0.0f }); }
			else if (input->PushKey(DIK_A)) { Object3d::CameraMoveEyeVector({ -1.0f,0.0f,0.0f }); }
		}

		object3d->Update();
		//object3d->BillBoardUpdate();

		//スペースキーを押していたら
		if (input->PushKey(DIK_SPACE))
		{
			//現在の座標を取得
			XMFLOAT2 position = sprite1->GetPosition();
			//移動後の座標を計算
			position.x += 1.0f;
			//座標の変更を反映
			sprite1->SetPosition(position);
		}

		if (input->TriggerKey(DIK_3))
		{
			scene_ = Scene::Particle;
		}
		else if (input->TriggerKey(DIK_2))
		{
			scene_ = Scene::BillboardOFF;
		}
		else
		{
			scene_ = Scene::BillboardON;
		}
		break;

	case GameScene::Scene::BillboardOFF:
		// オブジェクト移動
		if (input->PushKey(DIK_UP) || input->PushKey(DIK_DOWN) || input->PushKey(DIK_RIGHT) || input->PushKey(DIK_LEFT))
		{
			// 現在の座標を取得
			XMFLOAT3 position = object3d->GetPosition();

			position = { 100.0f,100.0f,100.0f };

			//// 移動後の座標を計算
			//if (input->PushKey(DIK_UP)) { position.y += 1.0f; }
			//else if (input->PushKey(DIK_DOWN)) { position.y -= 1.0f; }
			//if (input->PushKey(DIK_RIGHT)) { position.x += 1.0f; }
			//else if (input->PushKey(DIK_LEFT)) { position.x -= 1.0f; }

			// 座標の変更を反映
			object3d->SetPosition(position);
		}

		// カメラ移動
		if (input->PushKey(DIK_W) || input->PushKey(DIK_S) || input->PushKey(DIK_D) || input->PushKey(DIK_A))
		{
			if (input->PushKey(DIK_W)) { Object3d::CameraMoveEyeVector({ 0.0f,+1.0f,0.0f }); }
			else if (input->PushKey(DIK_S)) { Object3d::CameraMoveEyeVector({ 0.0f,-1.0f,0.0f }); }
			if (input->PushKey(DIK_D)) { Object3d::CameraMoveEyeVector({ +1.0f,0.0f,0.0f }); }
			else if (input->PushKey(DIK_A)) { Object3d::CameraMoveEyeVector({ -1.0f,0.0f,0.0f }); }
		}

		object3d->BillBoardUpdate();

		//スペースキーを押していたら
		if (input->PushKey(DIK_SPACE))
		{
			//現在の座標を取得
			XMFLOAT2 position = sprite1->GetPosition();
			//移動後の座標を計算
			position.x += 1.0f;
			//座標の変更を反映
			sprite1->SetPosition(position);
		}

		if (input->TriggerKey(DIK_3))
		{
			scene_ = Scene::Particle;
		}
		else if (input->TriggerKey(DIK_1))
		{
			scene_ = Scene::BillboardON;
		}
		else
		{
			scene_ = Scene::BillboardOFF;
		}

		break;

	case GameScene::Scene::Particle:
		// カメラ移動
		if (input->PushKey(DIK_W) || input->PushKey(DIK_S) || input->PushKey(DIK_D) || input->PushKey(DIK_A))
		{
			if (input->PushKey(DIK_W)) { ParticleManager::CameraMoveEyeVector({ 0.0f,+1.0f,0.0f }); }
			else if (input->PushKey(DIK_S)) { ParticleManager::CameraMoveEyeVector({ 0.0f,-1.0f,0.0f }); }
			if (input->PushKey(DIK_D)) { ParticleManager::CameraMoveEyeVector({ +1.0f,0.0f,0.0f }); }
			else if (input->PushKey(DIK_A)) { ParticleManager::CameraMoveEyeVector({ -1.0f,0.0f,0.0f }); }
		}
		particleMan->RandParticle();
		particleMan->Update();

		//スペースキーを押していたら
		if (input->PushKey(DIK_SPACE))
		{
			//現在の座標を取得
			XMFLOAT2 position = sprite1->GetPosition();
			//移動後の座標を計算
			position.x += 1.0f;
			//座標の変更を反映
			sprite1->SetPosition(position);
		}

		if (input->TriggerKey(DIK_1))
		{
			scene_ = Scene::BillboardON;
		}
		else if (input->TriggerKey(DIK_2))
		{
			scene_ = Scene::BillboardOFF;
		}
		else
		{
			scene_ = Scene::Particle;
		}
		break;
	}
}

void GameScene::Draw()
{
	// コマンドリストの取得
	ID3D12GraphicsCommandList* cmdList = dxCommon->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(cmdList);
	// 背景スプライト描画
	spriteBG->Draw();

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理

	// 3Dオブクジェクトの描画
	switch (scene_)
	{
	case GameScene::Scene::BillboardON:
		Object3d::PreDraw(cmdList);
		object3d->Draw();
		Object3d::PostDraw();
		break;
	case Scene::BillboardOFF:
		Object3d::PreDraw(cmdList);
		object3d->Draw();
		Object3d::PostDraw();
		break;
	case GameScene::Scene::Particle:
		ParticleManager::PreDraw(cmdList);
		particleMan->Draw();
		ParticleManager::PostDraw();
		break;
	}

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	// 3Dオブジェクト描画後処理
	

#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(cmdList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>
	//sprite1->Draw();
	//sprite2->Draw();
	switch (scene_)
	{
	case GameScene::Scene::BillboardON:
		
		break;
	case Scene::BillboardOFF:

		break;
	case GameScene::Scene::Particle:
		texture->Draw();
		break;
	}


	// デバッグテキストの描画
	debugText.DrawAll(cmdList);

	// スプライト描画後処理
	Sprite::PostDraw();
#pragma endregion
}
