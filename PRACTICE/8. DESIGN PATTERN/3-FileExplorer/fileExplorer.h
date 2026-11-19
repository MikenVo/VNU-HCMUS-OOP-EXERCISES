#include <iostream>
#include <vector>
using namespace std;

class Component {
protected:
	string name;
	long long size;
public:
	virtual string GetName() = 0;
	virtual float GetSize() = 0;
	virtual void List(int level = 0) = 0;
	virtual void AddComponent(Component* ifile) {}
	virtual void RemoveComponent(Component* ifile) {}
	virtual ~Component() {}
};

class Folder : public Component {
private:
	vector<Component*> components;

public:
	Folder(const string& name);
	string GetName();
	float GetSize();
	void List(int level) override;
	void AddComponent(Component* iComp);
	void RemoveComponent(const string& name);
	~Folder();
};

class File : public Component {
public:
	File(const string& name, long long size);
	string GetName() override;
	float GetSize() override;
	void List(int level) override;
	~File() override {}
};

class Disk {
private:
	std::string name;
	std::vector<Component*> components;

public:
	Disk(const std::string& name = "C:");
	~Disk();

	void AddComponent(Component* iComp);
	void List() const;
	Folder* CreateFolderUI(const string &folderName);
	long long TotalSize() const;
	std::string GetName() const;
};