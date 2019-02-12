#include "database.h"
//#include "datatypes.h"

Database::Database()
{
    const QString DRIVER("QSQLITE");
    if (QSqlDatabase::isDriverAvailable(DRIVER)){
        qDebug("QSQLITE driver available");
    }else{
        qDebug("QSQLITE driver not available");
        return;
    }

    db = QSqlDatabase::addDatabase(DRIVER);
    db.setDatabaseName("./cuacs_db.sql");
    if (!db.open()){
        qWarning() << "ERROR: " << db.lastError();
        return;
    }
}

int Database::initTables(){
    QSqlQuery query;
    query = QSqlQuery(db);

    // Initialize the database. If the tables are present then nothing will happen.
    if(!query.exec("CREATE TABLE staff (id INTEGER PRIMARY KEY, name TEXT)")){
        qWarning() << "ERROR: " << query.lastError().text();
    }
    if(!query.exec("CREATE TABLE client (name TEXT PRIMARY KEY)")){
        qWarning() << "ERROR: " << query.lastError().text();
    }
    if(!query.exec("CREATE TABLE animal (name TEXT PRIMARY KEY, species TEXT, breed TEXT, colour TEXT, special TEXT,"
                   "gender INTEGER, age INTEGER, weight INTEGER, height INTEGER, energy INTEGER, temperament INTEGER,"
                   "kid INTEGER, habits INTEGER, history INTEGER, dependency INTEGER, disease INTEGER, space INTEGER,"
                   "climate INTEGER, care INTEGER, cleanliness INTEGER, medical INTEGER, health INTEGER, "
                   "intelligence INTEGER, difficulty INTEGER, feeding INTEGER, noise INTEGER"
                   ")")){
        qWarning() << "ERROR: " << query.lastError().text();
    }

    return(0);
}

int Database::pushAnimal(AnimalData animal){
    QSqlQuery query;
    query = QSqlQuery(db);
    qDebug("Pushing animal into database.");

    if(!query.prepare("INSERT INTO animal VALUES (:name, :species, :breed, :colour, :special,"
                      ":gender, :age, :weight, :height, :energy, :temperament, :kid, :habits, :history,"
                      ":dependency, :disease, :space, :climate, :care, :cleanliness, :medical, :health,"
                      ":intelligence, :difficulty, :feeding, :noise"
                      ")")){
        qWarning() << "ERROR: " << query.lastError().text();
        return(1);
    }

    query.bindValue(":name", QString::fromStdString(animal.animalName));
    query.bindValue(":species", QString::fromStdString(animal.typeOfAnimal));
    query.bindValue(":breed", QString::fromStdString(animal.breed));
    query.bindValue(":colour", QString::fromStdString(animal.colour));
    query.bindValue(":special", QString::fromStdString(animal.specialSkill));
    query.bindValue(":gender", animal.animalAttr[0]);
    query.bindValue(":age", animal.animalAttr[1]);
    query.bindValue(":weight",animal.animalAttr[2]);
    query.bindValue(":height", animal.animalAttr[3]);
    query.bindValue(":energy", animal.animalAttr[4]);
    query.bindValue(":temperament", animal.animalAttr[5]);
    query.bindValue(":kid", animal.animalAttr[6]);
    query.bindValue(":habits", animal.animalAttr[7]);
    query.bindValue(":history", animal.animalAttr[8]);
    query.bindValue(":dependency", animal.animalAttr[9]);
    query.bindValue(":disease", animal.animalAttr[10]);
    query.bindValue(":space", animal.animalAttr[11]);
    query.bindValue(":climate", animal.animalAttr[12]);
    query.bindValue(":care", animal.animalAttr[13]);
    query.bindValue(":cleanliness", animal.animalAttr[14]);
    query.bindValue(":medical", animal.animalAttr[15]);
    query.bindValue(":health", animal.animalAttr[16]);
    query.bindValue(":intelligence", animal.animalAttr[17]);
    query.bindValue(":difficulty", animal.animalAttr[18]);
    query.bindValue(":feeding", animal.animalAttr[19]);
    query.bindValue(":noise", animal.animalAttr[20]);

    if(!query.exec()){
        qWarning() << "ERROR: " << query.lastError().text();
        query.finish();
        return(1);
    }
    query.finish();
    return(0);
}

AnimalData** Database::pullAnimals(){
    AnimalData** animals;
    QSqlQuery query = QSqlQuery(db);
    int i = 0;

    qDebug("Pulling animals from database.");
    if(!query.exec("SELECT * FROM animal")){
        qWarning() << "ERROR: " << query.lastError().text();
        query.finish();
        return NULL;
    }

    // Increment i for malloc below
    while (query.next()) {
          i++;
    }

    animals = (AnimalData**)malloc(i+1 * sizeof(**animals));
    int x = 0;
    for(; x < i; x++){
        animals[x] = new AnimalData;
    }

    x = 0;
    while (query.previous()){
         animals[x]->animalName = query.value(0).toString().toUtf8().constData();
         x++;
    }
    animals[i] = NULL;

    query.finish();
    return animals;
}
