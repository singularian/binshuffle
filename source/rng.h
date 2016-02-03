// rng.h
// uses predefined tables of random integers for shuffle

// #include <cstdint>

// extern int rngSet[500][100];
static unsigned long timeslast = 10;

// the add and sub will use blocks of 100+ numbers to add and subtract from  a file
unsigned long get_rand_list(int rng, unsigned long position, unsigned long size)
{
    int listnum = position % 100;
    int number  = 10;

    if (rng < 0) {
        rng = 0;
    }
    else if (rng <= 200) {
        number = (int) rngSet[rng][listnum];
    }
    else {
        number = rngSet[0][listnum];
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

  return a;

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

  return a;

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





