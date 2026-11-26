#include <iostream>
#include <vector>
#include "fileExplorer.h"
using namespace std;

int main() {
    Disk myDisk("C:");
    int choice = 0;

    while (true) {
        cout << "\n\n===== Disk Management [" << myDisk.GetName() << "] =====" << endl;
        cout << "1. Add a file" << endl;
        cout << "2. Add a folder" << endl;
        cout << "3. List all components" << endl;
        cout << "4. Calculate the total size" << endl;
        cout << "5. Exit the program" << endl;
        cout << "Input your choice: ";

        if (!(cin >> choice)) {
            break;
        }

        if (choice == 5) {
            cout << "Cleaning up the disk..." << endl;
            break;
        }

        if (choice == 1) {
            string fileName;
            long long fileSize = 0;
            cout << "Input the file name: ";
            cin >> fileName;
            cout << "Input the file size (Bytes): ";
            cin >> fileSize;

            myDisk.AddComponent(new File(fileName, fileSize));
            cout << "File stored successfully" << endl;
        }
        else if (choice == 2) {
            string folderName;
            cout << "Input the root folder name: ";
            cin >> folderName;

            myDisk.AddComponent(myDisk.CreateFolderUI(folderName));
            cout << "Folder added to disk" << endl;
        }
        else if (choice == 3) {
            cout << "\n\n--- DISK CONTENT ---" << endl;
            myDisk.List();
        }
        else if (choice == 4) {
            cout << "\n\nTotal current size: " << myDisk.TotalSize() << " Bytes" << endl;
        }
        else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}