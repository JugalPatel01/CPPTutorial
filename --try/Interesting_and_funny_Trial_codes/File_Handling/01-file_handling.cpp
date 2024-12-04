/*

--> open,      print,        read data,    write char,     reading char,   save and close the file
   fopen(),    fprintf(),    fscanf(),     fputc(),        fgetc(),        fclose()

--> move pointer,  write int,  read int,   size of file,   set the pointer at beginning
   fseek(),        fputw(),    fgetw(),    ftell(),        rewind()

*/

#include <iostream>
using namespace std;

int main()
{
   FILE *fp;
   fp = fopen("file.txt", "w+");

   // r for read , w for write, a for append, r+ for read and write(if file doesn't exist then return null),
   // w+ for read and write(if file doesn't exist then it will create the file), a+ for reading and appending
   // rb,wb,ab,rb+, wb+, ab+ are for binary files

   printf("%d\n", fp);
   cout << fp << endl;

   fprintf(fp, "%s", "hello ,this file file1 made by cpp program ");

   cout << fclose(fp); // 0 for success , -1 for failure(EOF)

   return 0;
}