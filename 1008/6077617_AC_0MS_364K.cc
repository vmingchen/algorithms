#include	<cstdio>
#include	<cstring>

using namespace std;

const char *HaabMonth[19] = {
    "pop",
    "no",
    "zip",
    "zotz",
    "tzec",
    "xul",
    "yoxkin",
    "mol",
    "chen",
    "yax",
    "zac",
    "ceh",
    "mac",
    "kankin",
    "muan",
    "pax",
    "koyab",
    "cumhu",
    "uayet",
};

const char *TzolkinDay[20] = {
    "imix",
    "ik",
    "akbal",
    "kan",
    "chicchan",
    "cimi",
    "manik",
    "lamat",
    "muluk",
    "ok",
    "chuen",
    "eb",
    "ben",
    "ix",
    "mem",
    "cib",
    "caban",
    "eznab",
    "canac",
    "ahau",
};

int haab2century(int day, const char *month, int year) 
{
    int im = 0;
    while ( im < 19 && strcmp(HaabMonth[im], month) != 0 ) im++;
    return year * 365 + im * 20 + day;
}

void centruy2tzolkin(int cent, int *number, int *name, int *year)
{
    *year = cent / 260;
    cent -= (*year)*260;
    *number = cent % 13 + 1;
    *name = cent % 20;
}

int main()
{
    int n, day, year, num, name, cent;
    char month[10];

    scanf("%d\n", &n);
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) {
	scanf("%d. %s %d\n", &day, month, &year);
	cent = haab2century(day, month, year);
	centruy2tzolkin(cent, &num, &name, &year);
	printf("%d %s %d\n", num, TzolkinDay[name], year);
    }
    return 0;
}
