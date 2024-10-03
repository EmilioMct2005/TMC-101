#include <stdio.h>

int main() {
    float costoGalon, consumoMin, consumoMax, litrosPorGalon = 3.78541;

    printf("Ingrese el costo del galon en pesos: ");
    scanf("%f", &costoGalon);

    printf("Ingrese el consumo minimo en litros por cada 100 km: ");
    scanf("%f", &consumoMin);

    printf("Ingrese el consumo maximo en litros por cada 100 km: ");
    scanf("%f", &consumoMax);

    if (consumoMin >= 0 && consumoMax >= consumoMin) {
        printf("| Consumo (L/100km) | Costo por km (pesos) |\n");

        for (float consumoLitros = consumoMin; consumoLitros <= consumoMax; consumoLitros += 1.0) {
            printf("|     %.1f L/100km     |     %.2f pesos     |\n", consumoLitros, (consumoLitros / 100) * (costoGalon / litrosPorGalon));
        }
    }

    return 0;
}
