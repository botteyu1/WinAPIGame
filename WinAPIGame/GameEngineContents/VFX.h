#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <vector>

// Ό³Έν :
class VFX : public GameEngineActor
{
public:
	// constrcuter destructer
	VFX();
	~VFX();

	// delete Function
	VFX(const VFX& _Other) = delete;
	VFX(VFX&& _Other) noexcept = delete;
	VFX& operator=(const VFX& _Other) = delete;
	VFX& operator=(VFX&& _Other) noexcept = delete;

	void Start() override;

	void Update(float _Delta) override;

	void Small_VFXOn(float4 _TilePos);
	void Hit_VFXOn(float4 _TilePos);
	void Blood_VFXOn(float4 _TilePos);
	void Huge_VFXOn(float4 _TilePos);
	void LovePlosion_VFXOn(float4 _TilePos);
	void UndeadDie_VFXOn(float4 _TilePos);
protected:

private:
	class BoneRenderer
	{
	public:
		GameEngineRenderer* Renderer = nullptr;
		float4 vec = float4::ZERO;
	};
	GameEngineRenderer* SmallRenderer = nullptr;
	GameEngineRenderer* HitRenderer = nullptr;
	GameEngineRenderer* BloodRenderer = nullptr;
	GameEngineRenderer* HugeRenderer = nullptr;
	GameEngineRenderer* LovePlosionRenderer = nullptr;
	std::vector<BoneRenderer> vecBoneRenderer ;

};

