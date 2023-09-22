void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int    i = 0;
    int             aux;

    while (i < size)
    {
        if (tab[i] > tab[i + 1])
        {
            aux = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = aux;
            i = 0;
        }
        else
            i++;  
    }
}