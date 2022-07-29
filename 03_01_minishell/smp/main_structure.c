int main(int argc, char **argv)
{
    handle_signal();
    init_list_and_struct();
    while (1)
    {
        prompt();
        get_cmd();
        parse_cmd();
        free_something();
    }
    return (0);
}