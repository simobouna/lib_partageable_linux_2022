#include <iostream>
#include <dlfcn.h>

int main(int argc, char ** argv)
{
	int data1 = 3;
	int data2 = 5;

	int valeur1;
	int valeur2;

	void *handle1 = dlopen("../lib/libComposant1.so", RTLD_LAZY);
	void *handle2 = dlopen("../lib/libComposant2.so", RTLD_LAZY);

    if (!handle1 || !handle2) {
        /* fail to load the library */
        fprintf(stderr, "Error: %s\n", dlerror());
        return EXIT_FAILURE;
    }
    int (*composant1)(int, int);
    int (*composant2)(int, int);

	composant1 = (int (*) (int, int)) dlsym(handle1, "composant1");
	composant2 = (int (*) (int, int)) dlsym(handle2, "composant2");

	// valeur1 =  composant1(data1,data2);

	// valeur2 =  composant2(data1,data2);

	//std::cout << getComposant1Version() << std::endl;
	std::cout << "valeur 1 :" << valeur1 << " valeur 2 :" << valeur2 << std::endl;

    dlclose(handle1);
    dlclose(handle2);
    return 0;
}

