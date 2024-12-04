/*
    # Accessing file system in C++
        -> "filesystem" library provides several features for interacting with the file system :
                -> creating, renaming and removing files and directories.
                -> checking file and directory properties
                -> reading and writing file metadata.
                -> traversing directories recursively.

        -> This "filesystem" library is defined in std::filesystem namespace.

*/

#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;
int main()
{
    // create new directory
    fs::create_directory("new_dir");

    // copy file from one file to second file
    if (fs::exists("file.txt"))
    {
        fs::copy_file("file.txt", "dst.txt", fs::copy_options::overwrite_existing);
    }
    /*
        other copy_options are :
        -> skip_existing
        -> update_existing
    */

    // rename/move file
    fs::rename("dst.txt", "new_dir/new_renamed_file.txt");

    // listing files in a directory using fs::directory_iterator(), fs::recursive_directory_iterator()
    for (const auto &file_entry : fs::directory_iterator("new_dir"))
    {
        cout << "path : " << file_entry.path() << endl;
    }

    fs::path p = "new_dir/new_renamed_file.txt";
    cout << "File name : " << p.filename() << "." << p.extension() << endl;

    // get file size
    cout << "size of file.txt is : " << fs::file_size("file.txt");

    // remove a file or directory
    if (fs::exists("dst.txt"))
    {
        fs::remove("dst.txt");
    }
    fs::remove_all("new_dir"); // recursively removes directory "new_dir"

    return 0;
}