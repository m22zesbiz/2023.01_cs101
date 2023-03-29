#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
typedef struct
{
    int receipt_id;
    int receipt_price;
    char receipt_time[32];
    int lotto_set[4][6];
} lotto_record_t;

int main()
{
    srand((unsigned)time(NULL));

    // get number of sets
    int n = 0;
    printf("請問你要買幾組樂透彩：");
    scanf("%d", &n);
    while (n > 5 || n < 0)
    {
        char temp;
        scanf("%c", &temp);
        printf("數字太大，請重新輸入：");
        scanf("%d", &n);
    }

    if (n != 0)
    {
        // open record file and check previous record
        int recordNum = 0;
        FILE *recordF;
        if ((recordF = fopen("record.bin", "rb+")) == NULL)
        {
            recordF = fopen("record.bin", "wb+");
        }
        else
        {
            recordF = fopen("record.bin", "rb+");
            char line[100];
            char *id_string;
            while (fgets(line, sizeof(line), recordF))
            {
                id_string = strstr(line, "id: ");
                if (id_string)
                {
                    id_string += strlen("id: ");
                    recordNum = atoi(id_string);
                }
            }
        }

        lotto_record_t record;
        record.receipt_id = ++recordNum;
        record.receipt_price = 100 * n;

        // opening lotto file
        char filename[20];
        sprintf(filename, "lotto[%05d].txt", recordNum);
        FILE *lottoF = fopen(filename, "w+");

        // printing header to lottoF
        printf("======== lotto649 ========\n");
        fprintf(lottoF, "======== lotto649 ========\n");
        printf("=======+ No.%05d +=======\n", recordNum);
        fprintf(lottoF, "=======+ No.%05d +=======\n", recordNum);
        time_t current_time;
        struct tm *local_time;
        char timeStr[30];
        current_time = time(NULL);
        local_time = localtime(&current_time);
        strftime(timeStr, sizeof(timeStr), "%a %b %d %H:%M:%S %Y", local_time);
        printf("=%s=\n", timeStr);
        fprintf(lottoF, "=%s=\n", timeStr);
        strcpy(record.receipt_time, timeStr);

        // generate lotto number
        for (int i = 0; i < n; i++)
        {
            int result[6];
            int numGen;
            int counter = 0;
            printf("[%d]: ", i + 1);
            fprintf(lottoF, "[%d]: ", i + 1);

            // first 6 number
            while (1)
            {
                numGen = floor(rand() % 69) + 1;
                for (int j = 0; j < counter + 1; j++)
                {
                    if (numGen == result[j])
                    {
                        j = counter + 1;
                    }
                    else if (numGen != result[j] && j == counter)
                    {
                        result[counter] = numGen;
                        counter++;
                        j = counter + 1;
                    }
                }
                if (counter == 6)
                {
                    break;
                }
            }

            // sorting numbers
            for (int j = 0; j < 6; j++)
            {
                for (int k = j + 1; k < 7; k++)
                {
                    if (result[j] > result[k])
                    {
                        int temp = result[j];
                        result[j] = result[k];
                        result[k] = temp;
                    }
                }
            }

            // special number
            counter = 0;
            while (1)
            {
                numGen = floor(rand() % 10) + 1;
                for (int j = 0; j < 7; j++)
                {
                    if (numGen == result[j])
                    {
                        j = 6;
                    }
                    else if (numGen != result[j] && j == 6)
                    {
                        result[6] = numGen;
                        counter = 6;
                        j = 6;
                    }
                }
                if (counter == 6)
                {
                    break;
                }
            }

            // printing result
            for (int j = 0; j < 7; j++)
            {
                printf("%02d ", result[j]);
                fprintf(lottoF, "%02d ", result[j]);
                record.lotto_set[i][j] = result[j];
            }

            printf("\n");
            fprintf(lottoF, "\n");
        }

        // printing empty set
        for (int i = 0; i < 5 - n; i++)
        {
            printf("[%d]: ", i + n + 1);
            fprintf(lottoF, "[%d]: ", i + n + 1);
            for (int j = 0; j < 7; j++)
            {
                printf("-- ");
                fprintf(lottoF, "-- ");
            }
            printf("\n");
            fprintf(lottoF, "\n");
        }

        // printing footer to lottoF
        printf("======== csie@CGU ========\n\n");
        fprintf(lottoF, "======== csie@CGU ========\n");

        // save record to record.bin
        fprintf(recordF, "id: %d\nprice: %d\ntime: ", record.receipt_id, record.receipt_price);
        for (int i = 0; i < 24; i++)
        {
            fprintf(recordF, "%c", record.receipt_time[i]);
        }
        fprintf(recordF, "\n");
        for (int i = 0; i < n; i++)
        {
            fprintf(recordF, "lotto_set [%d]: ", i);
            for (int j = 0; j < 7; j++)
            {
                fprintf(recordF, "%d ", record.lotto_set[i][j]);
            }
            fprintf(recordF, "\n");
        }
        fprintf(recordF, "\n");

        fclose(recordF);
        fclose(lottoF);
    }
    else
    {
        // open record file and check previous record
        FILE *recordF;
        if ((recordF = fopen("record.bin", "rb+")) == NULL)
        {
            printf("沒有買賣紀錄！");
        }

        // input for prize number
        int prizeNum[3];
        char temp;
        scanf("%c", &temp);
        printf("請輸入中獎號碼（最多三個）：");
        scanf("%d %d %d", &prizeNum[0], &prizeNum[1], &prizeNum[2]);
        while (prizeNum[0] > 69 || prizeNum[1] > 69 || prizeNum[2] > 69)
        {
            char temp;
            scanf("%c", &temp);
            printf("數字太大，請重新輸入：");
            scanf("%d %d %d", &prizeNum[0], &prizeNum[1], &prizeNum[2]);
        }
        printf("輸入中獎號碼為：%02d %02d %02d\n", prizeNum[0], prizeNum[1], prizeNum[2]);

        // getting record
        lotto_record_t record[1000];
        int currentRecord = 0;
        char line[100];
        while (fgets(line, sizeof(line), recordF))
        {
            if (strstr(line, "id:"))
            {
                record[currentRecord].receipt_id = atoi(line + strlen("id: "));
            }
            else if (strstr(line, "price:"))
            {
                record[currentRecord].receipt_price = atoi(line + strlen("price: "));
            }
            else if (strstr(line, "time:"))
            {
                strcpy(record[currentRecord].receipt_time, line + strlen("time: "));
                record[currentRecord].receipt_time[24] = '\0';
            }
            else if (strstr(line, "lotto_set"))
            {
                int setID = atoi(line + strlen("lotto_set ["));
                sscanf(line, "lotto_set [%*d]: %d %d %d %d %d %d %d ", &record[currentRecord].lotto_set[setID][0], &record[currentRecord].lotto_set[setID][1], &record[currentRecord].lotto_set[setID][2], &record[currentRecord].lotto_set[setID][3], &record[currentRecord].lotto_set[setID][4], &record[currentRecord].lotto_set[setID][5], &record[currentRecord].lotto_set[setID][6]);
                if (setID < 5) {
                    for (int i = 5; i > setID; i--) {
                        for (int j = 0; j < 7; j++) {
                            record[currentRecord].lotto_set[i][j] = 0;
                        }
                    }
                }
            }
            else if (strcmp(line, "\n") == 0)
            {
                currentRecord++;
                if (currentRecord >= 1000)
                {
                    printf("Reached maximum number of record\n");
                    break;
                }
            }
        }
        for (int i = 0; i < currentRecord; i++)
        {
            printf("Receipt ID: %d\n", record[i].receipt_id);
            printf("Price: %d\n", record[i].receipt_price);
            printf("Time: %s\n", record[i].receipt_time);
            for (int j = 0; j < 5; j++)
            {
                printf("Lotto set %d: ", j);
                for (int k = 0; k < 7; k++)
                {
                    printf("%d ", record[i].lotto_set[j][k]);
                }
                printf("\n");
            }
            printf("\n\n");
        }

        // print record for winning the lottery
        printf("以下為中獎彩卷︰\n");
        for (int i = 0; i < currentRecord; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                for (int k = 0; k < 7; k++)
                {
                    if (record[i].lotto_set[j][k] == prizeNum[0] || record[i].lotto_set[j][k] == prizeNum[1] || record[i].lotto_set[j][k] == prizeNum[2])
                    {
                        printf("彩卷 No.%d\n售出時間︰%s\n號碼︰", i + 1, record[i].receipt_time);
                        for (int l = 0; l < 7; l++)
                        {
                            printf("%02d ", record[i].lotto_set[j][l]);
                        }
                        k = 7; 
                        printf("\n");
                    }
                }
            }
        }
        printf("\n");

        fclose(recordF);
    }
}
