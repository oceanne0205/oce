/*
** EPITECH PROJECT, 2025
** my
** File description:
** Made By Ozy
*/
#ifndef MY_H
    #define MY_H
char *my_strdup(const char *src);
int my_strncmp(char const *s1, char const *s2, int n);
char *get_path_env(char **env);
int my_strcmp(const char *s1, const char *s2);
char *build_full_path(char *dir, char *cmd);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *find_path(char *cmd, char **env);
int has_slash(char *str);
void run_child(char *path, char **args, char **my_env);
int count_env_vars(char **envp);
char **copy_environment(char **envp);
char **my_unsetenv(char **args, char **env);
void display_env(char **my_env);
void free_env(char **my_env);
void my_cd(char **args, char **env);
void display_prompt(void);
void shell_loop(char **my_env);
int count_tokens(char *line);
char **split_line(char *line);
char **handle_command(char **args, char **my_env, int *should_exit);
void execute_command(char **args, char **my_env);
char *load_map(char *filepath);
void display_prompt(void);
void shell_loop(char **my_env);
void my_putchar(char c);
char *make_line(char *name, char *value);
char **add_env_var(char **env, char *name, char *value);
char **my_setenv(char **env, char *name, char *value);
int replace_env_var(char **env, char *name, char *value);
int my_printf(const char *format, ...);
#endif
