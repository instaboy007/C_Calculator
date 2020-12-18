#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

GtkBuilder *builder;
GtkWidget *window;
GtkTextView *Text_Entry;
GtkTextBuffer *buffer;

double evaluate(char[]);
int precedence(char);
double calculate(char, double, double);
char checknumber(char);

double evaluate(char expr[])
{
    double numbers[5];
    int nsi = 0;
    char operators[6];
    int osi = 0;
    char numbuf[32];
    int nbi = 0;
    char ch;
    int i = 0;

    while ((ch = expr[i]) != 0)
    {
        if (checknumber(ch))
        {
            numbuf[nbi++] = ch;
            if (!checknumber(expr[i + 1]))
            {
                numbuf[nbi] = 0;
                nbi = 0;
                sscanf(numbuf, "%lf", &numbers[nsi++]);
            }
        }
        else
res:6.907755^C
        {
            while ((osi > 0) && (precedence(ch) <= precedence(operators[osi - 1])))
            {
                numbers[nsi - 2] = calculate(operators[osi - 1], numbers[nsi - 2], numbers[nsi - 1]);
                osi--;
                nsi--;
            }
            operators[osi++] = ch;
        }
        i++;
    }
    while (osi > 0)
    {
        numbers[nsi - 2] = calculate(operators[osi - 1], numbers[nsi - 2], numbers[nsi - 1]);
        osi--;
        nsi--;
    }
    return numbers[0];
}

char checknumber(char ch)
{
    if ((ch >= '0' && ch <= '9') || ch == '.')
        return 1;
res:6.907755^C
    else
        return 0;
}
int precedence(char ch)
{
    int precedence;
    switch (ch)
    {
    case '+':
    case '-':
        precedence = 0;
        break;
    case '*':
    case '/':
        precedence = 1;
        break;
    case '^':
        precedence = 2;
    }
    return precedence;
}

double calculate(char moperator, double num1, double num2)
{
    double result = 0;
    switch (moperator)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    case '^':
        result = pow(num1, num2);
        break;
    default:
        gtk_text_buffer_set_text(buffer, "Invalid Operator\n", -1);
    }
    return result;
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("test.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

    gtk_builder_connect_signals(builder, NULL);
    Text_Entry = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "Text_entry"));
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(Text_Entry));

    gtk_widget_show_all(window);
    gtk_main();
    return EXIT_SUCCESS;
}

void on_window_destroy()
{
    gtk_main_quit();
}

void pressed1()
{
    gtk_text_buffer_insert_at_cursor(buffer, "1", 1);
}
void pressed2()
{
    gtk_text_buffer_insert_at_cursor(buffer, "2", 1);
}
void pressed3()
{
    gtk_text_buffer_insert_at_cursor(buffer, "3", 1);
}
void pressed4()
{
    gtk_text_buffer_insert_at_cursor(buffer, "4", 1);
}
void pressed5()
{
    gtk_text_buffer_insert_at_cursor(buffer, "5", 1);
}
void pressed6()
{
    gtk_text_buffer_insert_at_cursor(buffer, "6", 1);
}
void pressed7()
{
    gtk_text_buffer_insert_at_cursor(buffer, "7", 1);
}
void pressed8()
{
    gtk_text_buffer_insert_at_cursor(buffer, "8", 1);
}
void pressed9()
{
    gtk_text_buffer_insert_at_cursor(buffer, "9", 1);
}
void pressed0()
{
    gtk_text_buffer_insert_at_cursor(buffer, "0", 1);
}
void pressed_dot()
{
    gtk_text_buffer_insert_at_cursor(buffer, ".", 1);
}
void pressed_plus()
{
    gtk_text_buffer_insert_at_cursor(buffer, "+", 1);
}
void pressed_multiply()
{
    gtk_text_buffer_insert_at_cursor(buffer, "*", 1);
}
void pressed_minus()
{
    gtk_text_buffer_insert_at_cursor(buffer, "-", 1);
}
void pressed_slash()
{
    gtk_text_buffer_insert_at_cursor(buffer, "/", 1);
}
void pressed_modulus()
{
    gtk_text_buffer_insert_at_cursor(buffer, "(", 1);
}
void pressed_sin()
{
    gtk_text_buffer_insert_at_cursor(buffer, "sin(", 4);
}
void pressed_cos()
{
    gtk_text_buffer_insert_at_cursor(buffer, "cos(", 4);
}
void pressed_tan()
{
    gtk_text_buffer_insert_at_cursor(buffer, "tan(", 4);
}
void pressed_log()
{
    gtk_text_buffer_insert_at_cursor(buffer, "log(", 4);
}
void pressed_pow()
{
    gtk_text_buffer_insert_at_cursor(buffer, "^", 1);
}
void pressed_fact()
{
    gtk_text_buffer_insert_at_cursor(buffer, ")", 1);
}

char *str_replace(char *orig, char *rep, char *with)
{
    char *result;
    char *ins;
    char *tmp;
    int len_rep;
    int len_with;
    int len_front;
    int count;

    if (!orig || !rep)
        return NULL;
    len_rep = strlen(rep);
    if (len_rep == 0)
        return NULL;
    if (!with)
        with = "";
    len_with = strlen(with);

    ins = orig;
    for (count = 0; tmp = strstr(ins, rep); ++count)
    {
        ins = tmp + len_rep;
    }

    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    while (count--)
    {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep;
    }
    strcpy(tmp, orig);
    return result;
}

char *checker(char *str)
{
    int chk = 0;
    do
    {
        chk = 0;
        char *start, *end;
        start = strstr(str, "cos(");
        end = strstr(str, ")");
        int len = (int)(end - start);
        if (start != NULL && end != NULL && (len > 4))
        {
            double val = 0;
            char num[50] = {0}, cpy[50] = {0}, res_val[10] = {0};
            strncpy(num, start + 4, len - 4);
            strncpy(cpy, start, len + 1);
            val = atof(num);
            val = cos(val);
            sprintf(res_val, "%lf", val);
            str = str_replace(str, cpy, res_val);
            chk = 1;
        }
        start = strstr(str, "sin(");
        end = strstr(str, ")");
        len = (int)(end - start);
        if (start != NULL && end != NULL && (len > 4))
        {
            double val = 0;
            char num[50] = {0}, cpy[50] = {0}, res_val[10] = {0};
            strncpy(num, start + 4, len - 4);
            strncpy(cpy, start, len + 1);
            val = atoi(num);
            val = sin(val);
            sprintf(res_val, "%lf", val);
            str = str_replace(str, cpy, res_val);
            chk = 1;
        }
        start = strstr(str, "tan(");
        end = strstr(str, ")");
        len = (int)(end - start);
        if (start != NULL && end != NULL && (len > 4))
        {
            double val = 0;
            char num[50] = {0}, cpy[50] = {0}, res_val[10] = {0};
            strncpy(num, start + 4, len - 4);
            strncpy(cpy, start, len + 1);
            val = atoi(num);
            val = tan(val);
            sprintf(res_val, "%lf", val);
            str = str_replace(str, cpy, res_val);
            chk = 1;
        }
        start = strstr(str, "log(");
        end = strstr(str, ")");
        len = (int)(end - start);
        if (start != NULL && end != NULL && (len > 4))
        {
            double val = 0;
            char num[50] = {0}, cpy[50] = {0}, res_val[10] = {0};
            strncpy(num, start + 4, len - 4);
            strncpy(cpy, start, len + 1);
            val = atoi(num);
            val = log(val);
            sprintf(res_val, "%lf", val);
            str = str_replace(str, cpy, res_val);
            chk = 1;
        }
                
    } while (chk != 0);

    return str;
}

char *get_text(GtkTextView *text_view)
{
    GtkTextIter start, end;
    GtkTextBuffer *buffer = gtk_text_view_get_buffer((GtkTextView *)text_view);
    gchar *text;
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    return text;
}

double compute(char *str)
{
    double result;
    str = checker(str);
    g_print("\nres:%s", str);
    result = evaluate(str);
    return result;
}

void pressed_equal()
{
    char arr[100] = {0}, *str;
    double result;
    str = get_text(Text_Entry); 
    result = compute(str);
    sprintf(arr, "%lf", result);
    gtk_text_buffer_set_text(buffer, arr, -1);
}
void pressed_del()
{
    char arr[100] = {0};
    gtk_text_buffer_set_text(buffer, "", 1);
}
