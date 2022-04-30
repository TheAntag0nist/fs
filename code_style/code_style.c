Стиль кода обязательно выполнять везде.
Основной стиль: snake_case
Примечание: обратите внимание на фигурные скобки

1. Структуры
    typedef struct strcut_example{
    } struct_example;

2. Переменные
    int snake_case_int;
    float snake_case_float;

3. Функции
    void display_snake_case();

4. Константы
    #define MAX_SZ 10
    const int MAX_SZ = 10;

5. Перечисления
    enum fs_types{
        data_1,
        data_2
    };
	
	


6. Циклы
6.1 while (sum < const){ 
		sum = variable_1 + variable_2;
		variable_1 -= variable_2;
	}
	
6.2 do{
		sum = variable_1 + variable_2;
		variable_1 -= variable_2;
	} while (sum < const);
	
6.3 for (int i=1; i<=k; i++){
		sum -= i;
		variable_1 = sum%2;
	}

	
7. Условные операторы
7.1 if (variable_1 != 0){
		variable_1 -= variable_2;
		variable_2 += 15; 
	} else
		variable_1 += variable_2;
	
7.2 switch (sum){
		case 0:
			descending_sum;
			break;
		case 1:
			ascending_sum;
			break;
		default:
			unchanged_sum;
	}		

		