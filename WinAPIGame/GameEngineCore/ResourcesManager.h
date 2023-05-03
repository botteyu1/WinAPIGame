#pragma once
#include <string>
// ���� :
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

	// ���ϸ��� �� ã������ �̸��� �ȴ�.
	void TextureLoad(const std::string& _Path)
	{
		// _Path ���ϸ�

		// TextureLoad();
	}

	void TextureLoad(const std::string& _Name, const std::string& _Path)
	{

	}

	GameEngineTexture* FindTexture(const std::string& _Image);
	bool IsLoadTexture(const std::string& _Image);


protected:

private:
	// 2. ���ο� static �����͵� ���̵� ���� 1���� �д�.
	static ResourcesManager Inst;

	// static ResourcesManager* Inst;

	// 1. �����ڸ� private�ȿ� �ִ´�.
	ResourcesManager();
	~ResourcesManager();


};
