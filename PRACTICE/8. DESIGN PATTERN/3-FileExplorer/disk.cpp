#include <iostream>
#include <vector>
#include "fileExplorer.h"

Disk::Disk(const std::string& name) : name(name) {}

Disk::~Disk() {
	for (int i = 0; i < components.size(); i++) {
		delete components[i];
	}
	components.clear();
}

void Disk::AddComponent(Component* comp) {
	if (comp != nullptr) {
		components.push_back(comp);
	}
}

void Disk::List() const {
	std::cout << "Disk [" << name << "]:\n";
	for (int i = 0; i < components.size(); i++) {
		if (components[i] != nullptr) {
			components[i]->List(1);
		}
	}
}

long long Disk::TotalSize() const {
	long long total = 0;
	for (int i = 0; i < components.size(); i++) {
		if (components[i] != nullptr) {
			total += static_cast<long long>(components[i]->GetSize());
		}
	}
	return total;
}

Folder* Disk::CreateFolderUI(const string &folderName) {
	Folder *currentFolder = new Folder(folderName);
	int type;

	while (true) {
		cout << "\n\n[ Current Directory: " << folderName << " ]" << endl;
		cout << "Add a component (1: File, 2: Sub-folder, 0: Go back): ";

		if (!(cin >> type) || type == 0) {
			break;
		}

		if (type == 1) {
			string fName;
			long long fSize = 0;
			cout << "Input the file name: ";
			cin >> fName;
			cout << "Input the file size (bytes): ";
			cin >> fSize;
			currentFolder->AddComponent(new File(fName, fSize));
		}
		else if (type == 2) {
			string subName;
			cout << "Input the sub-folder name: ";
			cin >> subName;
			currentFolder->AddComponent(CreateFolderUI(subName));
		}
		else {
			cout << "Invalid choice" << endl;
		}
	}
	return currentFolder;
}

std::string Disk::GetName() const {
	return name;
}