#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef enum {
    STATUS_TEACHER = 1,
    STATUS_DOCENT,
    STATUS_DOCTOR
} status_t;

typedef struct {
    char* fam;
    char* name;
    status_t status;
} prepod_t;

static char* str_dup(const char* s) {
    assert(s);
    size_t len = strlen(s) + 1;
    char* r = malloc(len);
    assert(r);
    memcpy(r, s, len);
    return r;
}

static void prepod_free(prepod_t* p) {
    assert(p);
    free(p->fam);
    free(p->name);
}

static void prepod_print_header(void) {
    printf("+----+----------------+----------------+--------+\n");
    printf("| #  | Фамилия        | Имя            | Статус |\n");
    printf("+----+----------------+----------------+--------+\n");
}

static const char* status_to_str(status_t s) {
    switch (s) {
        case STATUS_TEACHER: return "преп";
        case STATUS_DOCENT:  return "доц";
        case STATUS_DOCTOR:  return "док";
        default: return "?";
    }
}

static void prepod_print_row(const prepod_t* p, size_t i) {
    printf("| %-2zu | %-14s | %-14s | %-6s |\n",
           i, p->fam, p->name, status_to_str(p->status));
}

static void prepod_print_table(const prepod_t* arr, size_t n) {
    prepod_print_header();
    for (size_t i = 0; i < n; ++i)
        prepod_print_row(&arr[i], i);
    printf("+----+----------------+----------------+--------+\n");
}

static bool prepod_match_name(const prepod_t* p, const char* fam, const char* name) {
    return strcmp(p->fam, fam) == 0 && strcmp(p->name, name) == 0;
}

static bool prepod_match_status(const prepod_t* p, status_t s) {
    return p->status == s;
}

static size_t prepod_find_by_name(
    const prepod_t* src, size_t n,
    const char* fam, const char* name,
    prepod_t** out
) {
    size_t cnt = 0;
    for (size_t i = 0; i < n; ++i)
        if (prepod_match_name(&src[i], fam, name))
            cnt++;

    if (cnt == 0) {
        *out = NULL;
        return 0;
    }

    prepod_t* res = malloc(cnt * sizeof(*res));
    assert(res);

    size_t j = 0;
    for (size_t i = 0; i < n; ++i)
        if (prepod_match_name(&src[i], fam, name))
            res[j++] = src[i];

    *out = res;
    return cnt;
}

static size_t prepod_find_by_status(
    const prepod_t* src, size_t n,
    status_t s,
    prepod_t** out
) {
    size_t cnt = 0;
    for (size_t i = 0; i < n; ++i)
        if (prepod_match_status(&src[i], s))
            cnt++;

    if (cnt == 0) {
        *out = NULL;
        return 0;
    }

    prepod_t* res = malloc(cnt * sizeof(*res));
    assert(res);

    size_t j = 0;
    for (size_t i = 0; i < n; ++i)
        if (prepod_match_status(&src[i], s))
            res[j++] = src[i];

    *out = res;
    return cnt;
}

int main(void) {
    size_t n = 0;
    printf("Количество преподавателей: ");
    if (scanf("%zu", &n) != 1 || n == 0)
        return EXIT_FAILURE;

    prepod_t* arr = malloc(n * sizeof(*arr));
    assert(arr);

    char buf_fam[64];
    char buf_name[64];
    int st;

    for (size_t i = 0; i < n; ++i) {
        printf("Фамилия: ");
        scanf("%63s", buf_fam);
        printf("Имя: ");
        scanf("%63s", buf_name);
        printf("Статус (1-3): ");
        scanf("%d", &st);

        arr[i].fam = str_dup(buf_fam);
        arr[i].name = str_dup(buf_name);
        arr[i].status = (status_t)st;
    }

    prepod_print_table(arr, n);

    printf("Поиск по фамилии и имени:\n");
    scanf("%63s %63s", buf_fam, buf_name);

    prepod_t* found = NULL;
    size_t found_n = prepod_find_by_name(arr, n, buf_fam, buf_name, &found);
    if (found_n)
        prepod_print_table(found, found_n);
    free(found);

    printf("Поиск по статусу (1-3): ");
    scanf("%d", &st);

    found_n = prepod_find_by_status(arr, n, (status_t)st, &found);
    if (found_n)
        prepod_print_table(found, found_n);
    free(found);

    for (size_t i = 0; i < n; ++i)
        prepod_free(&arr[i]);
    free(arr);

    return EXIT_SUCCESS;
}
