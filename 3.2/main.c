#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <time.h>

#define IP_ADDRESS_LENGTH 16 // Длина строки IP адреса

// Функция для преобразования IP адреса из строки в числовое представление
unsigned int ip_to_int(const char *ip) {
    struct in_addr addr;
    inet_pton(AF_INET, ip, &addr);
    return ntohl(addr.s_addr);
}

// Функция для проверки принадлежности IP адреса подсети
int is_in_subnet(unsigned int ip, unsigned int gateway, unsigned int subnet_mask) {
    return (ip & subnet_mask) == (gateway & subnet_mask);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Использование: %s <IP шлюза> <Маска подсети> <Количество пакетов>\n", argv[0]);
        return 1;
    }

    const char *gateway_ip = argv[1];
    const char *subnet_mask_ip = argv[2];
    int packet_count = atoi(argv[3]);

    if (packet_count <= 0) {
        printf("Количество пакетов должно быть положительным числом.\n");
        return 1;
    }

    unsigned int gateway = ip_to_int(gateway_ip);
    unsigned int subnet_mask = ip_to_int(subnet_mask_ip);
    
    int own_subnet_count = 0;
    int other_subnet_count = 0;

    srand(time(NULL)); // Инициализация генератора случайных чисел

    for (int i = 0; i < packet_count; i++) {
        // Генерация случайного IP адреса
        unsigned int random_ip = (rand() % 256) << 24 | (rand() % 256) << 16 | (rand() % 256) << 8 | (rand() % 256);
        
        if (is_in_subnet(random_ip, gateway, subnet_mask)) {
            own_subnet_count++;
        } else {
            other_subnet_count++;
        }
    }

    // Вывод статистики
    printf("Статистика отправленных пакетов:\n");
    printf("Пакеты в своей подсети: %d (%.2f%%)\n", own_subnet_count, (own_subnet_count / (float)packet_count) * 100);
    printf("Пакеты в других подсетях: %d (%.2f%%)\n", other_subnet_count, (other_subnet_count / (float)packet_count) * 100);

    return 0;
}
