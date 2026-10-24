#include <iostream>
#include <vector>
#include "fileExplorer.h"

// ===== Folder =====
Folder::Folder(const string& name) {
	this->name = name;
	this->size = 0.0;
}

string Folder::GetName() {
	return this->name;
}

float Folder::GetSize() {
	long long totalSize = 0;
	for (size_t i = 0; i < components.size(); i++) {
		if (components[i] != nullptr) {
			totalSize += components[i]->GetSize();
		}
	}
	return totalSize;
}

void Folder::List(int level) {
	string indent(level * 4, ' ');
	cout << indent << "+ [Folder] " << name << "\n";
	for (size_t i = 0; i < components.size(); i++) {
		if (components[i] != nullptr) {
			components[i]->List(level + 1);
		}
	}
}

void Folder::AddComponent(Component* iComp) {
	if (iComp != nullptr) {
		components.push_back(iComp);
	}
}

void Folder::RemoveComponent(const string& name) {
	if (components.empty()) {
		cout << "The folder is empty\n";
		return;
	}

	for (size_t i = 0; i < components.size(); ++i) {
		if (components[i]->GetName() == name) {
			delete components[i];
			components.erase(components.begin() + i);
			cout << "Removed component: " << name << endl;
			return;
		}
	}

	cout << "Component not found: " << name << "\n";
}

Folder::~Folder() {
	for (size_t i = 0; i < components.size(); i++) {
		delete components[i];
	}
	components.clear();
}





// ===== File =====
File::File(const string& name, long long size = 0) {
	this->name = name;
	this->size = size;
}

void File::List(int level) {
	string indent(level * 4, ' ');
	cout << indent << "- [File] " << name << " (" << size << " bytes)\n";
}

string File::GetName() {
	return this->name;
}

float File::GetSize() {
	return this->size;
}