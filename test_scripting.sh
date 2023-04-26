#!/bin/bash

# Regular cases
echo "ls" | ./simple_shell
echo "pwd" | ./simple_shell
echo "date" | ./simple_shell

# Edge cases
echo "" | ./simple_shell # empty command line
echo "    " | ./simple_shell # command line with only spaces
echo "command_does_not_exist" | ./simple_shell # non-existing command
echo "ls /does_not_exist" | ./simple_shell # non-existing directory

# Test EOF condition
echo -ne "ls\n" | ./simple_shell
echo -ne "pwd\n" | ./simple_shell
echo -ne "date\n" | ./simple_shell
echo -ne "\x04" | ./simple_shell # send EOF character (Ctrl-D)

# Test multiple commands
echo "ls && pwd && date" | ./simple_shell
echo "ls || pwd || date" | ./simple_shell
echo "ls; pwd; date" | ./simple_shell

# Test background execution
echo "sleep 5 &" | ./simple_shell
echo "echo 'Background command launched'" | ./simple_shell

# Test redirection
echo "ls > file.txt" | ./simple_shell
cat file.txt
rm file.txt

# Test error redirection
echo "ls /does_not_exist 2> error.txt" | ./simple_shell
cat error.txt
rm error.txt

# Test pipes
echo "ls -1 | wc -l" | ./simple_shell

# Test signal handling
echo "sleep 10" | ./simple_shell &
PID=$!
kill -2 $PID
wait $PID
