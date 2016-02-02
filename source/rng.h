// rng.h
// uses predefined tables of random integers for shuffle

// #include <cstdint>

static unsigned long timeslast = 10;

int rngSet1[100]  = {23, 207, 202, 36, 175, 153, 171, 186, 252, 235, 156, 166, 12, 32, 150, 254, 199, 88, 190, 240, 211, 163, 231, 65, 248, 116, 159, 154, 124, 172, 152, 138, 75, 200, 117, 249, 37, 21, 17, 6, 140, 226, 219, 122, 210, 62, 187, 155, 197, 89, 217, 107, 215, 15, 203, 119, 38, 222, 7, 29, 35, 228, 189, 143, 22, 131, 70, 73, 136, 74, 181, 112, 69, 1, 47, 105, 201, 85, 185, 118, 10, 137, 96, 3, 253, 198, 141, 212, 67, 20, 16, 71, 30, 91, 134, 92, 158, 223, 24, 177};

int rngSet2[100] = {34, 35, 29, 132, 134, 135, 31, 25, 223, 217, 188, 89, 164, 66, 252, 159, 23, 54, 114, 153, 233, 77, 24, 251, 187, 21, 106, 234, 79, 184, 173, 104, 53, 255, 232, 174, 210, 180, 109, 6, 218, 130, 249, 85, 62, 26, 194, 33, 141, 100, 129, 216, 131, 151, 139, 49, 98, 57, 92, 221, 177, 133, 93, 219, 47, 12, 245, 112, 46, 73, 120, 145, 189, 213, 195, 119, 40, 28, 243, 64, 55, 88, 74, 204, 95, 32, 158, 14, 144, 72, 224, 220, 69, 148, 172, 8, 170, 239, 5, 126};

int rngSet3[100] = {170, 163, 166, 98, 60, 65, 13, 63, 247, 55, 85, 209, 8, 126, 125, 16, 199, 67, 129, 249, 177, 86, 164, 153, 219, 211, 253, 213, 175, 195, 244, 241, 116, 224, 231, 6, 182, 179, 79, 24, 239, 235, 141, 49, 83, 96, 91, 139, 32, 240, 9, 2, 28, 87, 34, 178, 193, 3, 217, 215, 152, 42, 173, 214, 169, 148, 233, 105, 114, 62, 75, 102, 122, 218, 23, 68, 221, 194, 90, 237, 203, 47, 161, 123, 134, 130, 84, 234, 58, 245, 21, 66, 136, 22, 220, 184, 229, 147, 140, 180};

int rngSet4[100] = {1, 230, 208, 59, 68, 36, 247, 18, 177, 194, 40, 108, 113, 62, 211, 88, 92, 29, 64, 218, 179, 202, 80, 204, 188, 219, 128, 159, 140, 55, 180, 57, 91, 200, 245, 101, 161, 26, 117, 167, 232, 81, 125, 137, 124, 95, 76, 52, 60, 217, 170, 226, 44, 16, 207, 114, 243, 196, 107, 65, 84, 63, 214, 5, 123, 152, 111, 131, 143, 229, 241, 168, 134, 66, 110, 115, 132, 19, 174, 181, 198, 7, 49, 48, 127, 45, 195, 173, 189, 82, 187, 27, 53, 175, 67, 121, 75, 31, 41, 162};

int rngSet5[100] = {119, 51, 108, 50, 222, 101, 166, 103, 177, 128, 24, 106, 133, 160, 217, 22, 137, 144, 83, 14, 147, 232, 174, 117, 5, 163, 202, 129, 176, 112, 56, 2, 213, 150, 118, 47, 173, 247, 203, 27, 74, 212, 223, 18, 252, 70, 40, 231, 87, 197, 67, 168, 145, 134, 237, 187, 76, 175, 95, 29, 32, 36, 136, 255, 17, 1, 91, 31, 243, 184, 148, 73, 20, 60, 234, 23, 116, 207, 125, 239, 77, 4, 233, 84, 15, 131, 219, 238, 241, 194, 55, 68, 229, 38, 100, 39, 13, 157, 7, 249};

int rngSet6[100] = {139, 183, 65, 220, 46, 34, 101, 213, 219, 138, 70, 111, 12, 50, 47, 57, 173, 242, 105, 148, 237, 236, 196, 160, 185, 17, 53, 135, 143, 38, 191, 23, 168, 31, 124, 136, 218, 253, 29, 44, 118, 141, 26, 167, 188, 27, 245, 180, 4, 176, 194, 32, 18, 93, 247, 238, 6, 83, 144, 193, 229, 61, 199, 73, 58, 62, 76, 25, 177, 164, 120, 175, 251, 159, 102, 215, 48, 54, 207, 223, 55, 41, 224, 187, 11, 137, 249, 78, 170, 192, 216, 89, 19, 115, 59, 189, 42, 161, 221, 214};

int rngSet7[100] = {1, 170, 107, 111, 124, 167, 69, 91, 18, 110, 105, 17, 184, 219, 230, 94, 99, 132, 68, 183, 49, 11, 169, 34, 51, 208, 125, 22, 13, 236, 2, 5, 160, 117, 85, 66, 130, 181, 62, 197, 27, 204, 249, 55, 16, 82, 152, 40, 210, 254, 237, 153, 95, 15, 127, 157, 221, 154, 146, 201, 245, 158, 149, 161, 54, 151, 133, 96, 194, 139, 187, 98, 195, 75, 56, 244, 6, 71, 220, 150, 80, 200, 8, 21, 248, 42, 60, 4, 179, 61, 224, 116, 89, 246, 171, 212, 53, 32, 39, 29};

int rngSet8[100] = {18, 208, 252, 207, 234, 190, 246, 158, 52, 157, 78, 106, 44, 222, 79, 123, 154, 192, 61, 135, 178, 53, 71, 119, 148, 198, 244, 98, 167, 206, 66, 193, 181, 118, 230, 115, 137, 105, 117, 173, 84, 219, 65, 46, 180, 191, 218, 243, 114, 186, 40, 102, 133, 33, 36, 229, 57, 47, 189, 11, 132, 74, 166, 21, 130, 143, 108, 39, 56, 55, 59, 197, 60, 136, 49, 227, 214, 122, 93, 10, 26, 225, 127, 69, 62, 67, 4, 159, 88, 100, 188, 45, 163, 171, 153, 126, 175, 202, 176, 195};

int rngSet9[100] = {18, 208, 252, 207, 234, 190, 246, 158, 52, 157, 78, 106, 44, 222, 79, 123, 154, 192, 61, 135, 178, 53, 71, 119, 148, 198, 244, 98, 167, 206, 66, 193, 181, 118, 230, 115, 137, 105, 117, 173, 84, 219, 65, 46, 180, 191, 218, 243, 114, 186, 40, 102, 133, 33, 36, 229, 57, 47, 189, 11, 132, 74, 166, 21, 130, 143, 108, 39, 56, 55, 59, 197, 60, 136, 49, 227, 214, 122, 93, 10, 26, 225, 127, 69, 62, 67, 4, 159, 88, 100, 188, 45, 163, 171, 153, 126, 175, 202, 176, 195};

int rngSet10[100] = {92, 149, 219, 217, 137, 76, 77, 81, 173, 37, 198, 113, 151, 34, 138, 160, 111, 68, 39, 80, 15, 152, 123, 246, 72, 62, 127, 30, 42, 16, 25, 165, 247, 98, 146, 36, 27, 179, 17, 193, 234, 178, 205, 203, 139, 145, 19, 132, 22, 154, 244, 156, 196, 61, 194, 140, 101, 12, 216, 177, 70, 10, 45, 52, 143, 49, 227, 181, 28, 3, 228, 253, 161, 197, 242, 24, 225, 14, 238, 157, 170, 252, 166, 223, 237, 229, 210, 73, 251, 221, 82, 212, 192, 188, 224, 131, 214, 116, 79, 185};

int rngSet11[100] = {16, 85, 44, 217, 99, 15, 108, 240, 166, 28, 82, 169, 246, 206, 234, 92, 220, 37, 242, 13, 134, 181, 105, 3, 89, 57, 25, 124, 53, 31, 156, 215, 207, 158, 148, 154, 29, 42, 121, 205, 47, 126, 241, 123, 74, 182, 73, 255, 232, 56, 117, 177, 116, 248, 254, 198, 153, 39, 120, 30, 12, 173, 252, 55, 221, 114, 132, 76, 96, 129, 81, 70, 208, 35, 210, 127, 150, 75, 69, 160, 174, 94, 98, 238, 41, 48, 199, 112, 168, 60, 86, 91, 5, 161, 193, 152, 49, 109, 165, 142};

int rngSet12[100] = {192, 74, 69, 231, 31, 206, 142, 203, 166, 61, 184, 137, 28, 196, 65, 130, 63, 43, 76, 38, 30, 92, 100, 136, 228, 225, 171, 106, 47, 45, 213, 97, 115, 233, 78, 197, 238, 255, 8, 157, 204, 209, 122, 87, 139, 211, 149, 17, 189, 234, 212, 133, 99, 135, 239, 11, 124, 91, 200, 194, 220, 75, 40, 7, 168, 151, 27, 208, 161, 141, 107, 95, 186, 173, 6, 108, 148, 170, 162, 82, 14, 127, 4, 251, 159, 62, 44, 123, 175, 241, 21, 132, 72, 140, 33, 18, 90, 236, 165, 19};

// the add and sub will use blocks of 100+ numbers to add and subtract from  a file
unsigned long get_rand_list(int rng, unsigned long position, unsigned long size)
{
    int listnum = position % 100;
    int number  = 10;
    switch( rng ) 
    {
    case 0:
        number  = rngSet1[listnum];
        break;
    case 1:
        number  = rngSet2[listnum];
        break;
    case 2:
        number  = rngSet3[listnum];
        break;
    case 3:
        number  = rngSet4[listnum];
        break;
    case 4:
        number  = rngSet5[listnum];
        break;
    case 5:
        number  = rngSet6[listnum];
        break;
    case 6:
        number  = rngSet7[listnum];
        break;
    case 7:
        number  = rngSet8[listnum];
        break;
    case 8:
        number  = rngSet9[listnum];
        break;
    case 9:
        number  = rngSet10[listnum];
        break;
    case 10:
        number  = rngSet11[listnum];
        break;
    case 11:
        number  = rngSet12[listnum];
        break;
    }

    // return the random number from the rng set
    return number;
}

// add to the buffer
char* add_buffer_list(char *buffer, int rng, unsigned long buffer_size)
{
  unsigned long c   = 0;
  int add = 0;
  char a;
  char b;

  for (c=0;c<buffer_size;c++)
  {
     // printf("testing improvement %lu %lu\n", c, cx);
     add = get_rand_list(rng, c, buffer_size);
     a = (char )buffer[c] + add;
     buffer[c] = a;

  }

}

// add to the buffer
char* sub_buffer_list(char *buffer, int rng, unsigned long buffer_size)
{
  unsigned long c   = 0;
  int add = 0;
  char a;
  char b;
  for (c=0;c<buffer_size;c++)
  {
     // printf("testing improvement %lu %lu\n", c, cx);
     add = get_rand_list(rng, c, buffer_size);
     a = (char )buffer[c] - add;
     buffer[c] = a;

  }

}

void subtract_file_rnglist(char *name, int rng)
{

        FILE *file;
        char *buffer;
        unsigned long fileLen;

        //Open file
        file = fopen(name, "rb");
        if (!file)
        {
                fprintf(stderr, "Unable to open file %s\n", name);
                return;
        }

        //Get file length
        fseek(file, 0, SEEK_END);
        fileLen=ftell(file);
        fseek(file, 0, SEEK_SET);

        //Allocate memory
        buffer=(char *)malloc(fileLen+1);
        if (!buffer)
        {
                fprintf(stderr, "Memory error!");
                                fclose(file);
                return;
        }

        //Read file contents into buffer
        fread(buffer, fileLen, 1, file);
        fclose(file);

        printf("shuffle file size %lu \n", fileLen);

        int times = 0;
        for (times = 0; times < timeslast; times++) {
          printf("shuffle file list %lu \n", times);
          sub_buffer_list(buffer, rng, fileLen);
        }
        write_sub_buffer(name, buffer, fileLen);

        free(buffer);
}

void add_file_rnglist(char *name, int rng)
{

        FILE *file;
        char *buffer;
        unsigned long fileLen;

        //Open file
        file = fopen(name, "rb");
        if (!file)
        {
                fprintf(stderr, "Unable to open file %s\n", name);
                return;
        }

        //Get file length
        fseek(file, 0, SEEK_END);
        fileLen=ftell(file);
        fseek(file, 0, SEEK_SET);

        //Allocate memory
        buffer=(char *)malloc(fileLen+1);
        if (!buffer)
        {
                fprintf(stderr, "Memory error!");
                                fclose(file);
                return;
        }

        //Read file contents into buffer
        fread(buffer, fileLen, 1, file);
        fclose(file);

        printf("shuffle file size %lu \n", fileLen);

        int times = 0;
        for (times = 0; times < timeslast; times++) {
          printf("shuffle file list %lu \n", times);
          add_buffer_list(buffer, rng, fileLen);
        }
        write_add_buffer(name, buffer, fileLen);

        free(buffer);
}





