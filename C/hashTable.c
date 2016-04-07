#include <stdio.h>
#include <stdlib.h>


struct s_HashTable {
	int qtd, HASH_TABLE_SIZE;
	struct s_Companies** itens;
};

struct s_Companies {
	int cod;
	char name[30];
	float salary;
};

typedef struct s_HashTable Hash;


Hash* createHashTable(int HASH_TABLE_SIZE) {
	Hash* h = (Hash*)malloc(sizeof(Hash));

	if(h != NULL) {
		int i;

		h->HASH_TABLE_SIZE = HASH_TABLE_SIZE;
		h->itens = (struct s_Companies**)malloc(HASH_TABLE_SIZE * sizeof(struct s_Companies*));

		if(h->itens == NULL) {
			free(h);
			return NULL;
		}

		h->qtd = 0;

		for(i = 0; i < h->HASH_TABLE_SIZE; ++i)
			h->itens[i] = NULL;
	}
	return h;
}

void destroyHashTable(Hash* h) {
	if(h != NULL) {
		int i;

		for(i = 0; i < h->HASH_TABLE_SIZE; ++i) 
			if(h->itens[i] != NULL)
				free(h->itens[i]);
		free(h->itens);
		free(h);
	}
}


/**
	> Congruência linear multiplicativa
*/
int hashingByMult(int key, int HASH_TABLE_SIZE) {
	float K = 0.618666;
	float val = key * K;

	val = val - (int)val;

	return (int)(HASH_TABLE_SIZE * val);
}

/**
	> Congruência linear
*/
int hashingByDiv(int key, int HASH_TABLE_SIZE) {
	return (key & 0x7FFFFFFF) % HASH_TABLE_SIZE;
}


/**
	> Metódo de Dobras
*/
int hashingByFold(int key, int HASH_TABLE_SIZE) {
	const int SHIFTING = 10;

	// Deslocando o valor 10 bytes para direita
	int shift = key >> SHIFTING;
	// HASH_TABLE_SIZE  - 1 Por causa da array :)
	int limit = key & (HASH_TABLE_SIZE - 1);

	return (shift ^ limit);
}


int insertHashTable_NC(Hash* h, struct s_Companies companies) {
	if(h == NULL || h->qtd == h->HASH_TABLE_SIZE)
		return 0;
	
	struct s_Companies* newEmployee = (struct s_Companies*)malloc(sizeof(struct s_Companies));

	int key = companies.cod;
	int position = hashingByMult(key, h->HASH_TABLE_SIZE);

	if(newEmployee == NULL)
		return 0;

	*newEmployee = companies;
	h->itens[position] = newEmployee;

	h->qtd++;
	return 1;
}

int searchTable_NC(Hash* h, int cod, struct s_Companies* ref) {
	if(h == NULL)
		return 0;

	int position = hashingByMult(cod, h->HASH_TABLE_SIZE);

	if(h->itens[position] == NULL)
		return 0;

	*ref = *(h->itens[position]);
}

int main() {
	Hash* h = createHashTable(1024);
	int i;


	struct s_Companies func[3] = {{123, "Adejair Júnior", 3000}, {456, "Fulano Tal", 800}, {789, "Goku", 9999}};
	struct s_Companies firstEmployee;
	struct s_Companies secondEmployee;


	for(i = 0; i < 3; ++i)
		insertHashTable_NC(h, func[i]);
	searchTable_NC(h, func[0].cod, &firstEmployee);


	printf("%i %s %f\n", firstEmployee.cod, firstEmployee.name, firstEmployee.salary);
	printf("%i\n", hashingByMult(123, h->HASH_TABLE_SIZE));
	printf("%i\n", hashingByMult(456, h->HASH_TABLE_SIZE));
	printf("%i\n", hashingByMult(789, h->HASH_TABLE_SIZE));

	destroyHashTable(h);

	// CRASH PROGRAM, INVALID MEMORY HAHA
	// searchTable_NC(h, func[2].cod, &secondEmployee);
	// printf("%i %s %f\n", secondEmployee.cod, secondEmployee.name, secondEmployee.salary);

}