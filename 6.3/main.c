#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <dirent.h>
#include <string.h>
typedef double (*operation_func)(double, double);
void load_and_execute(const char *lib_path, const char *operation_name, double a, double b) {
    void *handle = dlopen(lib_path, RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Ошибка при загрузке библиотеки: %s\n", dlerror());
        return;
    }
    operation_func op = (operation_func)dlsym(handle, operation_name);
    if (!op) {
        fprintf(stderr, "Ошибка при загрузке функции: %s\n", dlerror());
        dlclose(handle);
        return;
    }
    double result = op(a, b);
    printf("Результат %s: %f\n", operation_name, result);
    dlclose(handle);
}
int main() {
    const char *lib_dir = "/home/uglygod46/VSCode/Lesson/6.3/lib/"; 
    const char *operations[] = {"add", "subtract", "multiply", "divide"};
    const char *lib_names[] = {"libadd.so", "libsubtract.so", "libmultiply.so", "libdivide.so"};
    
    double a, b;
    printf("Введите два числа: ");
    scanf("%lf %lf", &a, &b);
    for (int i = 0; i < 4; i++) {
        char lib_path[256];
        snprintf(lib_path, sizeof(lib_path), "%s%s", lib_dir, lib_names[i]);
        load_and_execute(lib_path, operations[i], a, b);
    }
    return 0;
}