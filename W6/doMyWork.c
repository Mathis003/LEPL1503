#include <pthread.h>

/*
* Function used to launch threads that will do the work for us.
*
* @long_computing : a function that will do a really long computing and that must be started by the thread.
*                 This function initially returns a pointer to an int and takes as argument a string.
*                 These have been casted into void* to match pthread_create() function specifications.
*                 You have to launch this function with the argument *string* and compare the returned value
*                 to *ret_value*. If the return value doesn't match *ret_value*,
*                 you have to launch another thread on the same argument with the function *backup_computing*.
*
* @backup_computing :  a backup function that must be used if the first thread didn't do the job correctly.
*                    As for *long_computing*, this function initially takes a string as argument and returns
*                    a pointer to an int.
*
* @string : the string that must be used as a parameter to both functions described above.
*
* @ret_value : the value to which the first returned code must be compared to to know if the first thread
*             correctly did the job or not.
*
* @return the int returned by the function started by the thread if no problem
*         -1 if you can't create the first thread
*         -2 if you can't join the first thread
*         -3 if you can't create the second thread
*         -4 if you can't join the second thread
*/
int doMyWork(void* long_computing(void*), void* backup_computing(void*), char* string, int ret_value)
{
    pthread_t main_thread;
    if (pthread_create(&main_thread, NULL, long_computing, (void *) string) != 0) { return -1; }

    void *result_main;
    if (pthread_join(main_thread, &result_main) != 0) { return -2; }

    if (*((int *) result_main) == ret_value) { return ret_value; }

    pthread_t backup_thread;
    if (pthread_create(&backup_thread, NULL, backup_computing, (void *) string) != 0) { return -3; }

    void *result_backup;
    if (pthread_join(backup_thread, &result_backup) != 0) { return -4; }

    return *((int *) result_backup);
}

int main() { return 0; }