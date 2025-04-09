#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char asignatura[3][30];
    char estudiantes[5][30];
    float notas[3][5];
    float spp, promedioF;
    float minNota, maxNota;
    float minNotaMateria[3], maxNotaMateria[3];
    int opc1, cont = 0, len;
    int aprobados, reprobados;
    int nombresIngresados = 0, materiasCompletas = 0;

    do
    {
        printf("\nSeleccione una opcion:\n");
        printf("1. Registro nombres\n");
        printf("2. Registro asignatura y notas\n");
        printf("3. Notas finales\n");
        printf("4. Notas mas altas y bajas\n");
        printf("5. Aprobados y reprobados\n");
        printf("6. Salir\n");
        printf(">> ");
        scanf("%d", &opc1);
        getchar();

        switch (opc1)
        {
        case 1:
            for (int i = 0; i < 5; i++)
            {
                do {
                    printf("Nombre estudiante %d: ", i + 1);
                    fgets(estudiantes[i], 30, stdin);
                    len = strlen(estudiantes[i]) - 1;
                    if (estudiantes[i][len] == '\n') estudiantes[i][len] = '\0';

                    if (strlen(estudiantes[i]) == 0)
                        printf("El nombre no puede estar vacio. Intente nuevamente.\n");

                } while (strlen(estudiantes[i]) == 0);
            }
            nombresIngresados = 1;
            break;

        case 2:
            if (!nombresIngresados)
            {
                printf("Debe ingresar los nombres de los estudiantes primero.\n");
                break;
            }

            if (cont >= 3)
            {
                printf("Ya ha ingresado las 3 materias requeridas.\n");
                break;
            }

            do {
                printf("Ingrese la asignatura %d: ", cont + 1);
                fgets(asignatura[cont], 30, stdin);
                len = strlen(asignatura[cont]) - 1;
                if (asignatura[cont][len] == '\n') asignatura[cont][len] = '\0';

                if (strlen(asignatura[cont]) == 0)
                    printf("El nombre de la asignatura no puede estar vacio. Intente nuevamente.\n");

            } while (strlen(asignatura[cont]) == 0);

            for (int i = 0; i < 5; i++)
            {
                do {
                    printf("%s - Ingrese la nota en %s (0-10): ", estudiantes[i], asignatura[cont]);
                    scanf("%f", &notas[cont][i]);

                    if (notas[cont][i] < 0 || notas[cont][i] > 10)
                        printf("Numero invalido. Ingrese nuevamente.\n");

                } while (notas[cont][i] < 0 || notas[cont][i] > 10);
            }

            cont++;
            if (cont == 3) materiasCompletas = 1;
            break;

        case 3:
            if (!materiasCompletas)
            {
                printf("Debe ingresar las 3 materias antes de ver las notas finales.\n");
                break;
            }

            printf("\nNotas finales de los estudiantes:\n");
            printf("%-20s", "Estudiantes");
            for (int i = 0; i < 5; i++)
            {
                printf("%-20s", estudiantes[i]);
            }
            printf("\n");

            for (int t = 0; t < 3; t++)
            {
                printf("%-20s", asignatura[t]);
                for (int i = 0; i < 5; i++)
                {
                    printf("%-20.2f", notas[t][i]);
                }
                printf("\n");
            }

            printf("%-20s", "Promedios");
            for (int i = 0; i < 5; i++)
            {
                spp = 0;
                for (int t = 0; t < 3; t++) spp += notas[t][i];

                promedioF = spp / 3;
                printf("%-20.2f", promedioF);
            }
            printf("\n");
            printf("\nPromedios por materia:\n");
            printf("%-20s%-20s\n", "Asignatura", "Promedio");
            for (int t = 0; t < 3; t++)
            {
                spp = 0;
                for (int i = 0; i < 5; i++) spp += notas[t][i];

                promedioF = spp / 5;
                printf("%-20s%-20.2f\n", asignatura[t], promedioF);
            }

            break;

        case 4:
            if (!materiasCompletas)
            {
                printf("Debe ingresar las 3 materias antes de ver las notas mas altas y bajas.\n");
                break;
            }

            printf("\nNotas mas altas y bajas por estudiante:\n");
            for (int i = 0; i < 5; i++)
            {
                maxNota = notas[0][i];
                minNota = notas[0][i];

                for (int t = 1; t < 3; t++)
                {
                    if (notas[t][i] > maxNota) maxNota = notas[t][i];
                    if (notas[t][i] < minNota) minNota = notas[t][i];
                }
                printf("%s - Nota mas alta: %.2f, Nota mas baja: %.2f\n", estudiantes[i], maxNota, minNota);
            }

            printf("\nNotas mas altas y bajas por materia:\n");
            for (int t = 0; t < 3; t++)
            {
                maxNotaMateria[t] = notas[t][0];
                minNotaMateria[t] = notas[t][0];

                for (int i = 1; i < 5; i++)
                {
                    if (notas[t][i] > maxNotaMateria[t]) maxNotaMateria[t] = notas[t][i];
                    if (notas[t][i] < minNotaMateria[t]) minNotaMateria[t] = notas[t][i];
                }
                printf("%s - Nota mas alta: %.2f, Nota mas baja: %.2f\n", asignatura[t], maxNotaMateria[t], minNotaMateria[t]);
            }
            break;

        case 5:
            if (!materiasCompletas)
            {
                printf("Debe ingresar las 3 materias antes de ver los aprobados y reprobados.\n");
                break;
            }

            printf("\nAprobados y reprobados:\n");
            for (int t = 0; t < 3; t++)
            {
                aprobados = 0;
                reprobados = 0;

                for (int i = 0; i < 5; i++)
                {
                    if (notas[t][i] >= 6)
                    {
                        aprobados++;
                    }
                    else
                    {
                        reprobados++;
                    }
                }

                printf("Asignatura: %s\n", asignatura[t]);
                printf("Aprobados: %d\n", aprobados);
                printf("Reprobados: %d\n", reprobados);
            }
            break;

        case 6:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opcion no valida. Intente nuevamente.\n");
            break;
        }
    } while (opc1 != 6);

    return 0;
}
