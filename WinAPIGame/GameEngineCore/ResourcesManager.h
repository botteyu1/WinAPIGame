#pragma once
#include <string>
// 설명 :
class GameEngineTexture;
class ResourcesManager
{
public:


	// delete Function
	ResourcesManager(const ResourcesManager& _Other) = delete;
	ResourcesManager(ResourcesManager&& _Other) noexcept = delete;
	ResourcesManager& operator=(const ResourcesManager& _Other) = delete;
	ResourcesManager& operator=(ResourcesManager&& _Other) noexcept = delete;

	static ResourcesManager& GetInst()
	{
		return Inst;
	}

	// 파일명이 곧 찾기위한 이름이 된다.
	void TextureLoad(const std::string& _Path)
	{
		// _Path 파일명

		// TextureLoad();
	}

	void TextureLoad(const std::string& _Name, const std::string& _Path)
	{

	}

	GameEngineTexture* FindTexture(const std::string& _Image);
	bool IsLoadTexture(const std::string& _Image);


protected:

private:
	// 2. 내부에 static 포인터든 값이든 뭐든 1개를 둔다.
	static ResourcesManager Inst;

	// static ResourcesManager* Inst;

	// 1. 생성자를 private안에 넣는다.
	ResourcesManager();
	~ResourcesManager();


};
