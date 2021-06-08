#pragma once

#include "include/std.h"

void StdFstream()
{
	std::ofstream myfile("./cfg.status", std::ios::out);
	myfile << "succees\n";
	myfile.close();
}

void LinuxSystemCall()
{
	char buf[20];
	strcpy(buf, "success");
	size_t nbytes = strlen(buf);

	int fd;
	fd = open("initialization.status", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
	write(fd, buf, nbytes);
	close(fd);
}