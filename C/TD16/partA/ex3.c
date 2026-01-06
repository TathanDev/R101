#include <stdio.h>
#include <stdlib.h>

int copie_svg()
{
    const char *src = "euclide.svg";
    const char *dst = "euclide_copie.svg";
    FILE *in = fopen(src, "rb");
    if (in == NULL)
    {
        perror("ouverture en lecture");
        return 1;
    }

    FILE *out = fopen(dst, "wb");
    if (out == NULL)
    {
        perror("ouverture en écriture");
        fclose(in);
        return 1;
    }

    int c;
    while ((c = fgetc(in)) != EOF)
    {
        fputc(c, out);
    }

    fclose(in);
    if (fclose(out) == EOF)
    {
        perror("erreur fermeture fichier sortie");
        return 1;
    }

    printf("Copie textuelle terminée avec succès.\n");
    return 0;
}

int copie_png()
{
    const char *src = "euclide.png";
    const char *dst = "euclide_copie.png";
    FILE *in = fopen(src, "rb");
    if (in == NULL)
    {
        perror("ouverture en lecture");
        return 1;
    }

    FILE *out = fopen(dst, "wb");
    if (out == NULL)
    {
        perror("ouverture en écriture");
        fclose(in);
        return 1;
    }

    unsigned char buffer[4096];

    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), in)) > 0)
    {
        fwrite(buffer, 1, bytesRead, out);
    }

    fclose(in);
    fclose(out);
    printf("Copie binaire terminée avec succès.\n");

    return 0;
}

int main(void)
{
    //copie_svg();
    copie_png();
    return 0;
}
