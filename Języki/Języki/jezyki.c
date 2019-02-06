#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// stuktura zawierające informacje osobowe
struct application {
	char* fullName; // string z imieniem
	char pesel[12]; // pesel ma zawsze 11 znaków + 1 bajt na \0
};

// struktura węzła listy podań
struct applicationNode {
	struct application* app; // wskaźnik na podanie
	struct applicationNode* next; // wskaźnik na kolejny element listy
};

// struktura zawierająca skrót języka i listę osób znających go
struct language {
	char languageName[4]; // język ma zawsze 3 znaki + 1 bajt na \0
	struct applicationNode* speakers; // lista osób władających językiem
};

// struktura węzła listy języków
struct languageNode {
	struct language* lg; // wskaśnik na przechowywany język
	struct languageNode* next; // wsk. na kolejny element listy
};

// alokuje pamięć dla nowego podania i ustawia w nim imię i nazwisko oraz pesel
struct application* createNewApplication(const char* fullName, const char* pesel) {
	struct application* newApplication = malloc(sizeof(struct application)); // alokujemy sizeof(struct application) bajtów

	newApplication->fullName = malloc(strlen(fullName) + 1); // alokujemy tyle bajtów ile znaków w imieniu i nazwisku + 1 dla \0
	strcpy(newApplication->fullName, fullName); // kopiujemy z bufora fullName do fullName

	strcpy(newApplication->pesel, pesel); // j.w.

	return newApplication;
}

// alokuje pamięć dla nowej listy aplikacji (używane do zrobienia pierwszego startowego węzła)
struct applicationNode* createApplicationNode() {
	struct applicationNode* newApplicationNode = malloc(sizeof(struct applicationNode));
	newApplicationNode->next = NULL; // ustawiamy wskaźnik na kolejnego potomka na NULL (list jest pusta)
	return newApplicationNode;
}

// przyjmuje start listy, zwraca ostatni węzeł listy
struct applicationNode* getLastApplicationNode(struct applicationNode* list) {
	while (list->next != NULL) { // dopóki węzeł ma potomka
		list = list->next; // przejdź do niego
	}
	return list;
}

// dodaje nowy węzeł na koniec listy podań
// list - wskaźnik na start listy,
// fullName - wskażnik na bufor trzymający imię i nazwisko,
// pesel - wskażnik na bufor trzymający pesel
void addNewApplicationNode(struct applicationNode* list, struct application* app) {
	struct applicationNode* newApplicationNode = malloc(sizeof(struct applicationNode)); // nowy węzeł

	newApplicationNode->app = app; // ustawiamy w nim podanie na to przekazane do dodania
	newApplicationNode->next = NULL; // i potomka na NULL jako że ten węzeł zostanie dodany jako ostatni

	list = getLastApplicationNode(list); // przejdz na koniec listy
	list->next = newApplicationNode; // ustaw potomka ostatniego elementu listy na nowy węzeł
}

// przyjmuje listę języków, skrót języka jaki ma dodać (albo zaktualizować listę osób znających go) oraz osobę która go zna
void addLanguageSpeaker(struct languageNode* list, char* language, struct application* speaker) {
	while (list->next != NULL) { // wyszukiwanie czy w liście istnieje już węzeł odpowiadający skrótowi
		list = list->next;

		if (strcmp(language, list->lg->languageName) == 0) { // porównanie skrótu przekazanego do funkcji z tym w węźle
			addNewApplicationNode(list->lg->speakers, speaker); // jeśli znaleziono dodajemy do listy znających go osób nową osobę
			return; // i uciekamy z funkcji aby nie wkonać kodu poniżej
		}
	}

	// tutaj jesteśmy jeśli nie znaleziono węzła odpowiadającego skrótowi

	struct languageNode* newLanguageNode = malloc(sizeof(struct languageNode)); // tworzymy węzeł

	newLanguageNode->lg = malloc(sizeof(struct language)); // i język do niego
	strcpy(newLanguageNode->lg->languageName, language);

	newLanguageNode->lg->speakers = createApplicationNode(); // i do niego języka pustą listę znających go osób
	addNewApplicationNode(newLanguageNode->lg->speakers, speaker); // i dodajemy osobę (podanie)

	newLanguageNode->next = NULL; // potomek na NULL, jest to ostatni el. listy języków
	list->next = newLanguageNode; // i dodajemy węzeł języka do listy języków
}

// przyjmuję stringa ze skrótami języków oddzielonymi spacjami, listę języków i znającą te języki osobę
void parseAndInsertLanguages(const char* languages, struct languageNode* lgNode, struct application* speaker) {
	int i, j; // iteratorki
	char singleLanguageBuffer[4]; // buforek dla pojedynczego skrótu
	singleLanguageBuffer[4] = '\0'; // 4 znak to zawsze \0 (skrót ma 3 znaki) więc ustawiamy go

	for (i = 0; languages[i] != '\0'; i += 4) { // dopóki lista języków ma jeszcze jakiś skrót (dokładnie sprawdzamy co 4 miejsca czy string się skończył (== \0))
		for (j = 0; j < 3; ++j) { // kopiujemy 3 kolejne znaki języka do bufora
			singleLanguageBuffer[j] = languages[j + i];
		}
		addLanguageSpeaker(lgNode, singleLanguageBuffer, speaker); // dodajemy podanie do listy języków
	}
}

// zwraca false przy "n" i true przy czymkolwiek innym
int promptForContinue() {
	char buf[2];
	printf("\nKontynuowac input? (y/n): ");
	scanf(" %2s", buf);
	return strcmp(buf, "n") != 0;
}

// przyjmuje listę języków i wypełnia ją przy użyciu podanych podań
void fillApplicationList(struct languageNode* lgNode) {
	char nameBuffer[255];
	char peselBuffer[12];
	char languageBuffer[255];


	do {
		printf("Prosze podac imie i nazwisko (max 255 znakow): ");
		// spacja przed % po to aby ignorować nową linię z stdin (sam nie do końca nie wiem ocb),
		// następnie 255 jako wielkość bufora,
		// następnie akceptowane znaki (wystkie różne od nowej linii) bo scanf domyślnie kończy się po spacji
		scanf(" %s", nameBuffer);
		while (getchar() != '\n')
			continue; /* czyści wiersz wejściowy */
		printf("\nProsze podac znane jezyki (max 255 znakow): ");
		scanf(" %s", languageBuffer);
			while (getchar() != '\n')
			continue; /* czyści wiersz wejściowy */	
		printf("\nProsze podac pesel (11 znakow): ");
		scanf(" %12s", peselBuffer);
		while (getchar() != '\n')
			continue; /* czyści wiersz wejściowy */




		// parsowanie listy języków na pojedyncze i wypełnianie listy
		parseAndInsertLanguages(languageBuffer, lgNode, createNewApplication(nameBuffer, peselBuffer));

	} while (promptForContinue());
};

// wyszukuje węzeł odpowiadający podanemu skrótowi, zwraca NULL jeśli nic nie znajdzie
struct languageNode* searchForLanguage(const char* language, struct languageNode* list) {
	while (list->next != NULL) {
		list = list->next;

		if (strcmp(language, list->lg->languageName) == 0) {
			return list;
		}
	}
	return NULL;
}

// wypisuje wszystkie podania z listy podań (przyjmuje węzeł języków i z niego pobiera listę podań)
void printApplications(struct languageNode* lgNode) {
	struct applicationNode* apps = lgNode->lg->speakers->next; // weź listę podań
	while (apps != NULL) {
		printf("\n\nImie i nazwisko: %s\nPesel: %s", apps->app->fullName, apps->app->pesel);
		apps = apps->next;
	}
}

// pyta o skrót języka i wypisuje podania
void printLanguageSpeakers(struct languageNode* lgList) {
	char languageBuffer[4];

	for (;;) {
		printf("\nPosze podac skrot jezyka (3 znaki): ");
		scanf(" %4[^\n]s", languageBuffer);

		struct languageNode* lgSearch = searchForLanguage(languageBuffer, lgList);

		if (lgSearch == NULL) {
			printf("\nBrak podan.\n");
		}
		else {
			printf("\nLista podan dla jezyka \"%s\":\n", languageBuffer);
			printf("\n--------------------------------------");
			printApplications(lgSearch);
			printf("\n\n--------------------------------------\n\n");
		}
	}
}



int main() {
	struct languageNode* lgList = malloc(sizeof(struct languageNode));
	lgList->next = NULL;

	fillApplicationList(lgList);

	printf("\n\n---------------------------------\n\n");

	printLanguageSpeakers(lgList);
	getchar();
	getchar();
	return 0;
}