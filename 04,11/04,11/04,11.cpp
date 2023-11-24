#include <iostream>
#include <string>
using namespace std;

const int MAX_FILMS = 20;

struct Film {
    string title;
    string director;
    string genre;
    float popularityRating;
    float price;
};

int addFilm(Film films[], int& numFilms, const string& title, const string& director, const string& genre, float popularityRating, float price) {
    if (numFilms < MAX_FILMS) {
        films[numFilms] = { title, director, genre, popularityRating, price };
        return ++numFilms;
    }
    else {
        cout << "The video store is full." << endl;
        return numFilms;
    }
}

void displayAllFilms(const Film films[], int numFilms) {
    if (numFilms == 0) {
        cout << "There are no films in the store." << endl;
        return;
    }

    cout << "List of all movies:" << endl;
    for (int i = 0; i < numFilms; ++i) {
        cout << "Movie " << i + 1 << ":" << endl;
        cout << "Title: " << films[i].title << endl;
        cout << "Director: " << films[i].director << endl;
        cout << "Genre: " << films[i].genre << endl;
        cout << "Popularity Rating: " << films[i].popularityRating << endl;
        cout << "Price: " << films[i].price << endl;
        cout << "-----------------------" << endl;
    }
}

void PopularFilm(const Film films[], int numFilms, const string& genre) {
    float maxPopularity = 0;
    Film mostPopularFilm;

    for (int i = 0; i < numFilms; ++i) {
        if (films[i].genre == genre) {
            if (films[i].popularityRating > maxPopularity) {
                maxPopularity = films[i].popularityRating;
                mostPopularFilm = films[i];
            }
        }
    }

    if (maxPopularity > 0) {
        cout << "The most popular film in the genre '" << genre << "':" << endl;
        cout << "Title: " << mostPopularFilm.title << endl;
        cout << "Director: " << mostPopularFilm.director << endl;
        cout << "Popularity Rating: " << mostPopularFilm.popularityRating << endl;
        cout << "Price: " << mostPopularFilm.price << endl;
    }
    else {
        cout << "Movies in the genre '" << genre << "' not found." << endl;
    }
}

void searchByField(const Film films[], int numFilms, int fieldChoice, const string& value) {
    bool found = false;

    for (int i = 0; i < numFilms; ++i) {
        switch (fieldChoice) {
        case 1:
            if (films[i].title == value) found = true;
            break;
        case 2:
            if (films[i].director == value) found = true;
            break;
        case 3:
            if (films[i].genre == value) found = true;
            break;
        default:
            cout << "Invalid field selection." << endl;
            return;
        }

        if (found) {
            cout << "Title: " << films[i].title << endl;
            cout << "Director: " << films[i].director << endl;
            cout << "Genre: " << films[i].genre << endl;
            cout << "Popularity Rating: " << films[i].popularityRating << endl;
            cout << "Price: " << films[i].price << endl;
            return;
        }
    }

    cout << "Movie with " << value << " was not found in the selected field." << endl;
}

int main() {
    Film films[MAX_FILMS];
    int numFilms = 0;

    numFilms = addFilm(films, numFilms, "Titanic", "James Cameron", "Romance", 8.5, 15.50);
    numFilms = addFilm(films, numFilms, "Mulan", "Nicky Caro", "Drama", 7.8, 10.50);
    numFilms = addFilm(films, numFilms, "Barbie", "Greta Gerwig", "Comedy", 8.2, 12.99);
    numFilms = addFilm(films, numFilms, "Oppenheimer", "Christopher Nolan", "Action", 8.2, 16.50);
    numFilms = addFilm(films, numFilms, "Hatiko", "Kristina Boden", "Drama", 8.2, 12.99);

    while (true) {
        cout << "\nSelect action:" << endl;
        cout << "1 - Search by field (Title, Director, Genre)" << endl;
        cout << "2 - Find the most popular movie in the genre" << endl;
        cout << "3 - Display all records" << endl;
        cout << "0 - Exit" << endl;

        int choice;
        cin >> choice;

        if (choice == 0) {
            break;
        }

        string value;
        if (choice == 1) {
            cout << "Select a search field (1 - Title, 2 - Director, 3 - Genre): ";
            int fieldChoice;
            cin >> fieldChoice;
            cout << "Enter search value: ";
            cin >> value;
            searchByField(films, numFilms, fieldChoice, value);
        }
        else if (choice == 2) {
            cout << "Enter the genre to search: ";
            cin >> value;
            PopularFilm(films, numFilms, value);
        }
        else if (choice == 3) {
            displayAllFilms(films, numFilms);
        }
    }

    return 0;
}
