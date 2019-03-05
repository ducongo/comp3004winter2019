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
    const QString DRIVER("QSQLITE");
    QSqlDatabase db2;
    db2 = QSqlDatabase::addDatabase(DRIVER);
    db2.setDatabaseName("./cuacs_db.sql");
    db2.open();
    query = QSqlQuery(db2);

    // Initialize the database. If the tables are present then nothing will happen.
    //query.exec("DROP TABLE staff;");
    //query.exec("DROP TABLE client;");
    //query.exec("DROP TABLE animal;");
    if(!query.exec("CREATE TABLE staff (id INTEGER PRIMARY KEY, name TEXT)")){
        qWarning() << "ERROR: " << query.lastError().text();
    }

    if(!query.exec("CREATE TABLE client (name TEXT PRIMARY KEY, home TEXT, email TEXT, breed TEXT, species TEXT,"
                   "homePhone INTEGER, mobilePhone INTEGER, age INTEGER, gender INTEGER, economicBackground INTEGER,"
                   "activity INTEGER, experience INTEGER, patience INTEGER, house INTEGER, time INTEGER, strength INTEGER"
                   ")")){
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

int Database::pushClient(ClientData client){
    QSqlQuery query;
    const QString DRIVER("QSQLITE");
    QSqlDatabase db2;
    db2 = QSqlDatabase::addDatabase(DRIVER);
    db2.setDatabaseName("./cuacs_db.sql");
    db2.open();
    query = QSqlQuery(db2);
    qDebug("Pushing client into database.");

    if(!query.prepare("INSERT INTO client VALUES(:name, :home, :email, :breed, :species,"
                      ":homePhone, :mobilePhone, :age, :gender, :economicBackground,"
                      ":activity, :experience, :patience, :house, :time, :strength"
                      ")")){
        qWarning() << "ERROR: " << query.lastError().text();
        return(1);
    }

    query.bindValue(":name", QString::fromStdString(client.clientName));
    query.bindValue(":home", QString::fromStdString(client.clientAddr));
    query.bindValue(":email", QString::fromStdString(client.clientEmail));
    query.bindValue(":breed", QString::fromStdString(client.breed));
    query.bindValue(":species", QString::fromStdString(client.species));
    query.bindValue(":homePhone", client.clientAttr[0]);
    query.bindValue(":mobilePhone", client.clientAttr[1]);
    query.bindValue(":age", client.clientAttr[2]);
    query.bindValue(":gender", client.clientAttr[3]);
    query.bindValue(":economicBackground", client.clientAttr[4]);
    query.bindValue(":activity", client.clientAttr[5]);
    query.bindValue(":experience", client.clientAttr[6]);
    query.bindValue(":patience", client.clientAttr[7]);
    query.bindValue(":house", client.clientAttr[8]);
    query.bindValue(":time", client.clientAttr[9]);
    query.bindValue(":strength", client.clientAttr[10]);

    if(!query.exec()){
        qWarning() << "ERROR: " << query.lastError().text();
        query.finish();
        return(1);
    }
    query.finish();
    return(0);
}

int Database::pushStaff(StaffData staff){
    QSqlQuery query;
    query = QSqlQuery(db);
    qDebug("Pushing staff into database.");

    if(!query.prepare("INSERT INTO staff VALUES(:id, :name)")){
        qWarning() << "ERROR: " << query.lastError().text();
        return(1);
    }

    query.bindValue(":id", staff.staffId);
    query.bindValue(":name", QString::fromStdString(staff.staffName));

    if(!query.exec()){
        qWarning() << "ERROR: " << query.lastError().text();
        query.finish();
        return(1);
    }
    query.finish();
    return(0);
}

int Database::pushAnimal(AnimalData animal){
    QSqlQuery query;
    const QString DRIVER("QSQLITE");
    QSqlDatabase db2;
    db2 = QSqlDatabase::addDatabase(DRIVER);
    db2.setDatabaseName("./cuacs_db.sql");
    db2.open();
    query = QSqlQuery(db2);
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

int Database::updateAnimal(AnimalData animal){
    QSqlQuery query;
    query = QSqlQuery(db);
    qDebug("Update animal in database.");

    if(!query.prepare("UPDATE animal"
                      "SET species=:species, breed=:breed, colour=:colour, special=:special,"
                      "gender=:gender, age=:age, weight=:weight, height=:height, energy=:energy, "
                      "temperament=:temperament, kid=:kid, habits=:habits, history=:history,"
                      "dependency=:dependency, disease=:disease, space=:space, climate=:climate, "
                      "care=:care, cleanliness:cleanliness, medical:medical, health=:health,"
                      "intelligence=:intelligence, difficulty=:difficulty, feeding=:feeding, noise=:noise"
                      "WHERE name=:name"
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

    return 0;
}

int Database::updateClient(ClientData client){
    QSqlQuery query;
    query = QSqlQuery(db);
    qDebug("Pushing client into database.");

    if(!query.prepare("UPDATE client "
                      "SET email=:email, breed=:breed, species=:species,"
                      "homePhone=:homePhone, mobilePhone:mobilePhone, age=:age, gender=:gender, "
                      "economicBackground:economicBackground, activity=:activity, experience=:experience, "
                      "patience=:patience, house=:house, time=:time, strength=:strength"
                      "WHERE name=:name)")){
        qWarning() << "ERROR: " << query.lastError().text();
        return(1);
    }

    query.bindValue(":name", QString::fromStdString(client.clientName));
    query.bindValue(":home", QString::fromStdString(client.clientAddr));
    query.bindValue(":email", QString::fromStdString(client.clientEmail));
    query.bindValue(":breed", QString::fromStdString(client.breed));
    query.bindValue(":species", QString::fromStdString(client.species));
    query.bindValue(":homePhone", client.clientAttr[0]);
    query.bindValue(":mobilePhone", client.clientAttr[1]);
    query.bindValue(":age", client.clientAttr[2]);
    query.bindValue(":gender", client.clientAttr[3]);
    query.bindValue(":economicBackground", client.clientAttr[4]);
    query.bindValue(":activity", client.clientAttr[5]);
    query.bindValue(":experience", client.clientAttr[6]);
    query.bindValue(":patience", client.clientAttr[7]);
    query.bindValue(":house", client.clientAttr[8]);
    query.bindValue(":time", client.clientAttr[9]);
    query.bindValue(":strength", client.clientAttr[10]);

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
    QSqlQuery query;
    const QString DRIVER("QSQLITE");
    QSqlDatabase db2;
    db2 = QSqlDatabase::addDatabase(DRIVER);
    db2.setDatabaseName("./cuacs_db.sql");
    db2.open();
    query = QSqlQuery(db2);

    int i = 0;

    qDebug("Pulling animals from database.");
    if(!query.exec("SELECT name, species, breed, colour, special,"
                   "gender, age, weight, height, energy, temperament, kid, habits, history,"
                   "dependency, disease, space, climate, care, cleanliness, medical, health,"
                   "intelligence, difficulty, feeding, noise FROM animal")){
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
         animals[x]->typeOfAnimal = query.value(1).toString().toUtf8().constData();
         animals[x]->breed = query.value(2).toString().toUtf8().constData();
         animals[x]->colour = query.value(3).toString().toUtf8().constData();
         animals[x]->specialSkill = query.value(4).toString().toUtf8().constData();
         animals[x]->animalAttr[0] = query.value(5).toInt();
         animals[x]->animalAttr[1] = query.value(6).toInt();
         animals[x]->animalAttr[2] = query.value(7).toInt();
         animals[x]->animalAttr[3] = query.value(8).toInt();
         animals[x]->animalAttr[4] = query.value(9).toInt();
         animals[x]->animalAttr[5] = query.value(10).toInt();
         animals[x]->animalAttr[6] = query.value(11).toInt();
         animals[x]->animalAttr[7] = query.value(12).toInt();
         animals[x]->animalAttr[8] = query.value(13).toInt();
         animals[x]->animalAttr[9] = query.value(14).toInt();
         animals[x]->animalAttr[10] = query.value(15).toInt();
         animals[x]->animalAttr[11] = query.value(16).toInt();
         animals[x]->animalAttr[12] = query.value(17).toInt();
         animals[x]->animalAttr[13] = query.value(18).toInt();
         animals[x]->animalAttr[14] = query.value(19).toInt();
         animals[x]->animalAttr[15] = query.value(20).toInt();
         animals[x]->animalAttr[16] = query.value(21).toInt();
         animals[x]->animalAttr[17] = query.value(22).toInt();
         animals[x]->animalAttr[18] = query.value(23).toInt();
         animals[x]->animalAttr[19] = query.value(24).toInt();
         animals[x]->animalAttr[20] = query.value(25).toInt();

         x++;
    }
    animals[i] = NULL;

    query.finish();
    return animals;
}

ClientData** Database::pullClients(){
    ClientData** clients;
    QSqlQuery query;
    const QString DRIVER("QSQLITE");
    QSqlDatabase db2;
    db2 = QSqlDatabase::addDatabase(DRIVER);
    db2.setDatabaseName("./cuacs_db.sql");
    db2.open();
    query = QSqlQuery(db2);
    int i = 0;

    qDebug("Pulling clients from database.");
    if(!query.exec("SELECT name, home, email, breed, species, homePhone, mobilePhone,"
                   "age, gender, economicBackground, activity, experience, patience, house, time,"
                   "strength FROM client")){
        qWarning() << "ERROR: " << query.lastError().text();
        query.finish();
        return NULL;
    }

    // Increment i for malloc below
    while (query.next()) {
          i++;
    }

    clients = (ClientData**)malloc(i+1 * sizeof(**clients));
    int x = 0;
    for(; x < i; x++){
        clients[x] = new ClientData;
    }

    x = 0;
    while (query.previous()){
         clients[x]->clientName      = query.value(0).toString().toUtf8().constData();
         clients[x]->clientAddr      = query.value(1).toString().toUtf8().constData();
         clients[x]->clientEmail     = query.value(2).toString().toUtf8().constData();
         clients[x]->breed           = query.value(3).toString().toUtf8().constData();
         clients[x]->species         = query.value(4).toString().toUtf8().constData();
         clients[x]->clientAttr[0]   = query.value(5).toInt();
         clients[x]->clientAttr[1]   = query.value(6).toInt();
         clients[x]->clientAttr[2]   = query.value(7).toInt();
         clients[x]->clientAttr[3]   = query.value(8).toInt();
         clients[x]->clientAttr[4]   = query.value(9).toInt();
         clients[x]->clientAttr[5]   = query.value(10).toInt();
         clients[x]->clientAttr[6]   = query.value(11).toInt();
         clients[x]->clientAttr[7]   = query.value(12).toInt();
         clients[x]->clientAttr[8]   = query.value(13).toInt();
         clients[x]->clientAttr[9]   = query.value(14).toInt();
         clients[x]->clientAttr[10]  = query.value(15).toInt();

         x++;
    }
    clients[i] = NULL;

    query.finish();
    return clients;
}

int Database::initValues(){
    QSqlQuery query;
    const QString DRIVER("QSQLITE");
    QSqlDatabase db2;
    db2 = QSqlDatabase::addDatabase(DRIVER);
    db2.setDatabaseName("./cuacs_db.sql");
    db2.open();
    query = QSqlQuery(db2);

    ClientData client1;
    ClientData client2;
    ClientData client3;
    ClientData client4;
    ClientData client5;

    AnimalData animal1;
    AnimalData animal2;
    AnimalData animal3;
    AnimalData animal4;
    AnimalData animal5;
    AnimalData animal6;
    AnimalData animal7;
    AnimalData animal8;
    AnimalData animal9;
    AnimalData animal10;
    AnimalData animal11;
    AnimalData animal12;
    AnimalData animal13;
    AnimalData animal14;
    AnimalData animal15;
    AnimalData animal16;
    AnimalData animal17;
    AnimalData animal18;
    AnimalData animal19;
    AnimalData animal20;
    AnimalData animal21;
    AnimalData animal22;
    AnimalData animal23;
    AnimalData animal24;
    AnimalData animal25;

    client1.clientName = "Kyle";
    client1.clientAttr[0] = 665994999;
    client1.clientAttr[1] = 553817834;
    client1.clientAddr = "1049 Bank Street, Ottawa, Ontario";
    client1.clientEmail = "kyle@rogers.ca";
    client2.clientName = "Parfait";
    client2.clientAttr[0] = 735647366;
    client2.clientAttr[1] = 133808184;
    client2.clientAddr = "4309 49 St, Yellow Knife, Nunavut";
    client2.clientEmail = "parfait@gmail.com";
    client3.clientName = "Victor";
    client3.clientAttr[0] = 663011942;
    client3.clientAttr[1] = 884813436;
    client3.clientAddr = "381 St-Catherine St W, Montral, Quebec";
    client3.clientEmail = "victor@hotmail.com";
    client4.clientName = "Curtis";
    client4.clientAttr[0] = 666076301;
    client4.clientAttr[1] = 888481346;
    client4.clientAddr = "601 5 St Sw, Calgary, Alberta"            ;
    client4.clientEmail = "curtis@mcgill.ca";
    client5.clientName = "Phil";
    client5.clientAttr[0] = 502530000;
    client5.clientAttr[1] = 669956636;
    client5.clientAddr = "100 Queen St W, Toronto, Ontario";
    client5.clientEmail = "phil@cmail.carleton.ca";

    animal1.animalName = "Victor";
    animal2.animalName = "Kyle";
    animal3.animalName = "Parfait";
    animal4.animalName = "John";
    animal5.animalName = "Ringo";
    animal6.animalName = "Rogue";
    animal7.animalName = "Bella";
    animal8.animalName = "Lucy";
    animal9.animalName = "Daisy";
    animal10.animalName = "Lily";
    animal11.animalName = "Maggie";
    animal12.animalName = "Molly";
    animal13.animalName = "Charlie";
    animal14.animalName = "Luna";
    animal15.animalName = "Stella";
    animal16.animalName = "Ellie";
    animal17.animalName = "Abby";
    animal18.animalName = "Coco";
    animal19.animalName = "Chloe";
    animal20.animalName = "Sophie";
    animal21.animalName = "Mufin";
    animal22.animalName = "Rootbeer";
    animal23.animalName = "Lizzy";
    animal24.animalName = "Panther";
    animal25.animalName = "Peter";

    animal1.typeOfAnimal="Dog";
    animal2.typeOfAnimal="Cat";
    animal3.typeOfAnimal="Dog";
    animal4.typeOfAnimal="Cat";
    animal5.typeOfAnimal="Bear";
    animal6.typeOfAnimal="Bird";
    animal7.typeOfAnimal="Fish";
    animal8.typeOfAnimal="Bear";
    animal9.typeOfAnimal="Bear";
    animal10.typeOfAnimal="Fish";
    animal11.typeOfAnimal="Dog";
    animal12.typeOfAnimal="Dog";
    animal13.typeOfAnimal="Cat";
    animal14.typeOfAnimal="Fish";
    animal15.typeOfAnimal="Fish";
    animal16.typeOfAnimal="Bear";
    animal17.typeOfAnimal="Bear";
    animal18.typeOfAnimal="Bear";
    animal19.typeOfAnimal="Bird";
    animal20.typeOfAnimal="Cat";
    animal21.typeOfAnimal="Dog";
    animal22.typeOfAnimal="Bear";
    animal23.typeOfAnimal="Dog";
    animal24.typeOfAnimal="Cat";
    animal25.typeOfAnimal="Dog";

    animal1.breed = "Blacklab";
    animal2.breed = "Calico";
    animal3.breed = "Corgi";
    animal4.breed = "Leopard";
    animal5.breed = "Polar";
    animal6.breed = "Parrot";
    animal7.breed = "Goldfish";
    animal8.breed = "Black";
    animal9.breed = "Panda";
    animal10.breed = "Dwarflanternshark";
    animal11.breed = "Shiba Inu";
    animal12.breed = "Bulldog";
    animal13.breed = "Calico";
    animal14.breed = "Carp";
    animal15.breed = "Koi";
    animal16.breed = "Grizzly";
    animal17.breed = "Polar";
    animal18.breed = "Black";
    animal19.breed = "Eagle";
    animal20.breed = "Panther";
    animal21.breed = "Blacklab";
    animal22.breed = "Panda";
    animal23.breed = "Bulldog";
    animal24.breed = "Leopard";
    animal25.breed = "German";

    animal1.colour = "Brown";
    animal2.colour = "Gray";
    animal3.colour = "Blue";
    animal4.colour = "Pink";
    animal5.colour = "Black";
    animal6.colour = "All";
    animal7.colour = "Brown";
    animal8.colour = "Gray";
    animal9.colour = "Blue";
    animal10.colour = "Pink";
    animal11.colour = "Black";
    animal12.colour = "Brown";
    animal13.colour = "Gray";
    animal14.colour = "Blue";
    animal15.colour = "Pink";
    animal16.colour = "Black";
    animal17.colour = "Brown";
    animal18.colour = "Gray";
    animal19.colour = "Blue";
    animal20.colour = "Pink";
    animal21.colour = "Black";
    animal22.colour = "Brown";
    animal23.colour = "Gray";
    animal24.colour = "Blue";
    animal25.colour = "Pink";

    animal1.specialSkill = "Seeing-eye";
    animal11.specialSkill = "Seeing-eye";
    animal12.specialSkill = "Show";
    animal15.specialSkill = "Drug-sniffing";
    animal20.specialSkill = "Hunting";
    animal21.specialSkill = "Security";

    animal1.animalAttr[0] = 0;
    animal2.animalAttr[0] = 0;
    animal3.animalAttr[0] = 0;
    animal4.animalAttr[0] = 1;
    animal5.animalAttr[0] = 1;
    animal6.animalAttr[0] = 1;
    animal7.animalAttr[0] = 0;
    animal8.animalAttr[0] = 0;
    animal9.animalAttr[0] = 0;
    animal10.animalAttr[0] = 1;
    animal11.animalAttr[0] = 1;
    animal12.animalAttr[0] = 1;
    animal13.animalAttr[0] = 0;
    animal14.animalAttr[0] = 0;
    animal15.animalAttr[0] = 0;
    animal16.animalAttr[0] = 1;
    animal17.animalAttr[0] = 1;
    animal18.animalAttr[0] = 1;
    animal19.animalAttr[0] = 0;
    animal20.animalAttr[0] = 1;
    animal21.animalAttr[0] = 0;
    animal22.animalAttr[0] = 1;
    animal23.animalAttr[0] = 1;
    animal24.animalAttr[0] = 0;
    animal25.animalAttr[0] = 0;

    animal1.animalAttr[1] = 9;
    animal2.animalAttr[1] = 6;
    animal3.animalAttr[1] = 7;
    animal4.animalAttr[1] = 2;
    animal5.animalAttr[1] = 3;
    animal6.animalAttr[1] = 4;
    animal7.animalAttr[1] = 5;
    animal8.animalAttr[1] = 8;
    animal9.animalAttr[1] = 11;
    animal10.animalAttr[1] = 12;
    animal11.animalAttr[1] = 2;
    animal12.animalAttr[1] = 3;
    animal13.animalAttr[1] = 18;
    animal14.animalAttr[1] = 16;
    animal15.animalAttr[1] = 15;
    animal16.animalAttr[1] = 4;
    animal17.animalAttr[1] = 11;
    animal18.animalAttr[1] = 7;
    animal19.animalAttr[1] = 9;
    animal20.animalAttr[1] = 10;
    animal21.animalAttr[1] = 12;
    animal22.animalAttr[1] = 13;
    animal23.animalAttr[1] = 3;
    animal24.animalAttr[1] = 5;
    animal25.animalAttr[1] = 4;

    animal1.animalAttr[2] = 100;
    animal2.animalAttr[2] = 10;
    animal3.animalAttr[2] = 90;
    animal4.animalAttr[2] = 6;
    animal5.animalAttr[2] = 400;
    animal6.animalAttr[2] = 3;
    animal7.animalAttr[2] = 1;
    animal8.animalAttr[2] = 251;
    animal9.animalAttr[2] = 300;
    animal10.animalAttr[2] = 20;
    animal11.animalAttr[2] = 20;
    animal12.animalAttr[2] = 30;
    animal13.animalAttr[2] = 18;
    animal14.animalAttr[2] = 30;
    animal15.animalAttr[2] = 8;
    animal16.animalAttr[2] = 5;
    animal17.animalAttr[2] = 11;
    animal18.animalAttr[2] = 401;
    animal19.animalAttr[2] = 450;
    animal20.animalAttr[2] = 300;
    animal21.animalAttr[2] = 26;
    animal22.animalAttr[2] = 40;
    animal23.animalAttr[2] = 35;
    animal24.animalAttr[2] = 366;
    animal25.animalAttr[2] = 66;

    animal1.animalAttr[3] = 36;
    animal2.animalAttr[3] = 13;
    animal3.animalAttr[3] = 40;
    animal4.animalAttr[3] = 12;
    animal5.animalAttr[3] = 50;
    animal6.animalAttr[3] = 7;
    animal7.animalAttr[3] = 2;
    animal8.animalAttr[3] = 36;
    animal9.animalAttr[3] = 41;
    animal10.animalAttr[3] = 18;
    animal11.animalAttr[3] = 30;
    animal12.animalAttr[3] = 33;
    animal13.animalAttr[3] = 24;
    animal14.animalAttr[3] = 13;
    animal15.animalAttr[3] = 8;
    animal16.animalAttr[3] = 72;
    animal17.animalAttr[3] = 80;
    animal18.animalAttr[3] = 49;
    animal19.animalAttr[3] = 19;
    animal20.animalAttr[3] = 39;
    animal21.animalAttr[3] = 34;
    animal22.animalAttr[3] = 65;
    animal23.animalAttr[3] = 25;
    animal24.animalAttr[3] = 40;
    animal25.animalAttr[3] = 42;

    animal1.animalAttr[4] = 1;
    animal2.animalAttr[4] = 3;
    animal3.animalAttr[4] = 2;
    animal4.animalAttr[4] = 2;
    animal5.animalAttr[4] = 1;
    animal6.animalAttr[4] = 3;
    animal7.animalAttr[4] = 3;
    animal8.animalAttr[4] = 3;
    animal9.animalAttr[4] = 1;
    animal10.animalAttr[4] = 1;
    animal11.animalAttr[4] = 1;
    animal12.animalAttr[4] = 1;
    animal13.animalAttr[4] = 2;
    animal14.animalAttr[4] = 1;
    animal15.animalAttr[4] = 3;
    animal16.animalAttr[4] = 2;
    animal17.animalAttr[4] = 2;
    animal18.animalAttr[4] = 3;
    animal19.animalAttr[4] = 2;
    animal20.animalAttr[4] = 1;
    animal21.animalAttr[4] = 2;
    animal22.animalAttr[4] = 3;
    animal23.animalAttr[4] = 3;
    animal24.animalAttr[4] = 2;
    animal25.animalAttr[4] = 1;

    animal1.animalAttr[5] = 3;
    animal2.animalAttr[5] = 3;
    animal3.animalAttr[5] = 2;
    animal4.animalAttr[5] = 3;
    animal5.animalAttr[5] = 1;
    animal6.animalAttr[5] = 1;
    animal7.animalAttr[5] = 3;
    animal8.animalAttr[5] = 1;
    animal9.animalAttr[5] = 2;
    animal10.animalAttr[5] = 2;
    animal11.animalAttr[5] = 2;
    animal12.animalAttr[5] = 2;
    animal13.animalAttr[5] = 3;
    animal14.animalAttr[5] = 3;
    animal15.animalAttr[5] = 2;
    animal16.animalAttr[5] = 2;
    animal17.animalAttr[5] = 2;
    animal18.animalAttr[5] = 1;
    animal19.animalAttr[5] = 1;
    animal20.animalAttr[5] = 2;
    animal21.animalAttr[5] = 3;
    animal22.animalAttr[5] = 2;
    animal23.animalAttr[5] = 2;
    animal24.animalAttr[5] = 3;
    animal25.animalAttr[5] = 1;

    animal1.animalAttr[5] = 1;
    animal2.animalAttr[5] = 1;
    animal3.animalAttr[5] = 1;
    animal4.animalAttr[5] = 3;
    animal5.animalAttr[5] = 2;
    animal6.animalAttr[5] = 1;
    animal7.animalAttr[5] = 1;
    animal8.animalAttr[5] = 2;
    animal9.animalAttr[5] = 2;
    animal10.animalAttr[5] = 3;
    animal11.animalAttr[5] = 3;
    animal12.animalAttr[5] = 3;
    animal13.animalAttr[5] = 3;
    animal14.animalAttr[5] = 2;
    animal15.animalAttr[5] = 2;
    animal16.animalAttr[5] = 3;
    animal17.animalAttr[5] = 3;
    animal18.animalAttr[5] = 2;
    animal19.animalAttr[5] = 1;
    animal20.animalAttr[5] = 1;
    animal21.animalAttr[5] = 1;
    animal22.animalAttr[5] = 2;
    animal23.animalAttr[5] = 2;
    animal24.animalAttr[5] = 3;
    animal25.animalAttr[5] = 2;

    animal1.animalAttr[6] = 1;
    animal2.animalAttr[6] = 2;
    animal3.animalAttr[6] = 1;
    animal4.animalAttr[6] = 3;
    animal5.animalAttr[6] = 2;
    animal6.animalAttr[6] = 2;
    animal7.animalAttr[6] = 3;
    animal8.animalAttr[6] = 3;
    animal9.animalAttr[6] = 3;
    animal10.animalAttr[6] = 3;
    animal11.animalAttr[6] = 3;
    animal12.animalAttr[6] = 3;
    animal13.animalAttr[6] = 3;
    animal14.animalAttr[6] = 3;
    animal15.animalAttr[6] = 3;
    animal16.animalAttr[6] = 3;
    animal17.animalAttr[6] = 3;
    animal18.animalAttr[6] = 2;
    animal19.animalAttr[6] = 3;
    animal20.animalAttr[6] = 1;
    animal21.animalAttr[6] = 3;
    animal22.animalAttr[6] = 2;
    animal23.animalAttr[6] = 2;
    animal24.animalAttr[6] = 2;
    animal25.animalAttr[6] = 2;

    animal1.animalAttr[70] = 1;
    animal2.animalAttr[7] = 2;
    animal3.animalAttr[7] = 2;
    animal4.animalAttr[7] = 2;
    animal5.animalAttr[7] = 1;
    animal6.animalAttr[7] = 1;
    animal7.animalAttr[7] = 2;
    animal8.animalAttr[7] = 2;
    animal9.animalAttr[7] = 1;
    animal10.animalAttr[7] = 2;
    animal11.animalAttr[7] = 3;
    animal12.animalAttr[7] = 3;
    animal13.animalAttr[7] = 3;
    animal14.animalAttr[7] = 3;
    animal15.animalAttr[7] = 3;
    animal16.animalAttr[7] = 3;
    animal17.animalAttr[7] = 3;
    animal18.animalAttr[7] = 3;
    animal19.animalAttr[7] = 3;
    animal20.animalAttr[7] = 3;
    animal21.animalAttr[7] = 2;
    animal22.animalAttr[7] = 2;
    animal23.animalAttr[7] = 2;
    animal24.animalAttr[7] = 3;
    animal25.animalAttr[7] = 2;

    animal1.animalAttr[8] = 2;
    animal2.animalAttr[8] = 3;
    animal3.animalAttr[8] = 2;
    animal4.animalAttr[8] = 2;
    animal5.animalAttr[8] = 1;
    animal6.animalAttr[8] = 3;
    animal7.animalAttr[8] = 1;
    animal8.animalAttr[8] = 1;
    animal9.animalAttr[8] = 2;
    animal10.animalAttr[8] = 2;
    animal11.animalAttr[8] = 2;
    animal12.animalAttr[8] = 2;
    animal13.animalAttr[8] = 3;
    animal14.animalAttr[8] = 3;
    animal15.animalAttr[8] = 3;
    animal16.animalAttr[8] = 3;
    animal17.animalAttr[8] = 3;
    animal18.animalAttr[8] = 2;
    animal19.animalAttr[8] = 2;
    animal20.animalAttr[8] = 2;
    animal21.animalAttr[8] = 1;
    animal22.animalAttr[8] = 2;
    animal23.animalAttr[8] = 3;
    animal24.animalAttr[8] = 2;
    animal25.animalAttr[8] = 1;

    animal1.animalAttr[9] = 3;
    animal2.animalAttr[9] = 2;
    animal3.animalAttr[9] = 2;
    animal4.animalAttr[9] = 3;
    animal5.animalAttr[9] = 2;
    animal6.animalAttr[9] = 3;
    animal7.animalAttr[9] = 3;
    animal8.animalAttr[9] = 3;
    animal9.animalAttr[9] = 2;
    animal10.animalAttr[9] = 2;
    animal11.animalAttr[9] = 3;
    animal12.animalAttr[9] = 1;
    animal13.animalAttr[9] = 1;
    animal14.animalAttr[9] = 2;
    animal15.animalAttr[9] = 3;
    animal16.animalAttr[9] = 1;
    animal17.animalAttr[9] = 3;
    animal18.animalAttr[9] = 3;
    animal19.animalAttr[9] = 3;
    animal20.animalAttr[9] = 2;
    animal21.animalAttr[9] = 2;
    animal22.animalAttr[9] = 3;
    animal23.animalAttr[9] = 2;
    animal24.animalAttr[9] = 1;
    animal25.animalAttr[9] = 2;

    // living sppace 1 is ranch 2 is house 3 is apartment
    animal1.animalAttr[10] = 2;
    animal2.animalAttr[10] = 3;
    animal3.animalAttr[10] = 3;
    animal4.animalAttr[10] = 2;
    animal5.animalAttr[10] = 2;
    animal6.animalAttr[10] = 1;
    animal7.animalAttr[10] = 3;
    animal8.animalAttr[10] = 2;
    animal9.animalAttr[10] = 2;
    animal10.animalAttr[10] = 1;
    animal11.animalAttr[10] = 2;
    animal12.animalAttr[10] = 2;
    animal13.animalAttr[10] = 2;
    animal14.animalAttr[10] = 3;
    animal15.animalAttr[10] = 1;
    animal16.animalAttr[10] = 1;
    animal17.animalAttr[10] = 1;
    animal18.animalAttr[10] = 1;
    animal19.animalAttr[10] = 1;
    animal20.animalAttr[10] = 2;
    animal21.animalAttr[10] = 2;
    animal22.animalAttr[10] = 2;
    animal23.animalAttr[10] = 2;
    animal24.animalAttr[10] = 2;
    animal25.animalAttr[10] = 2;

    // Climate 1 is cold weather 2 is moderate 3 is tropical
    animal1.animalAttr[11] = 1;
    animal2.animalAttr[11] = 2;
    animal3.animalAttr[11] = 3;
    animal4.animalAttr[11] = 1;
    animal5.animalAttr[11] = 2;
    animal6.animalAttr[11] = 3;
    animal7.animalAttr[11] = 3;
    animal8.animalAttr[11] = 3;
    animal9.animalAttr[11] = 1;
    animal10.animalAttr[11] = 2;
    animal11.animalAttr[11] = 2;
    animal12.animalAttr[11] = 1;
    animal13.animalAttr[11] = 1;
    animal14.animalAttr[11] = 1;
    animal15.animalAttr[11] = 2;
    animal16.animalAttr[11] = 3;
    animal17.animalAttr[11] = 1;
    animal18.animalAttr[11] = 3;
    animal19.animalAttr[11] = 2;
    animal20.animalAttr[11] = 2;
    animal21.animalAttr[11] = 1;
    animal22.animalAttr[11] = 2;
    animal23.animalAttr[11] = 2;
    animal24.animalAttr[11] = 3;
    animal25.animalAttr[11] = 3;

    //level of care required 1 is intense 2 is requent 3 is lowest frequency
    animal1.animalAttr[12] = 1;
    animal2.animalAttr[12] = 2;
    animal3.animalAttr[12] = 3;
    animal4.animalAttr[12] = 3;
    animal5.animalAttr[12] = 2;
    animal6.animalAttr[12] = 3;
    animal7.animalAttr[12] = 3;
    animal8.animalAttr[12] = 1;
    animal9.animalAttr[12] = 1;
    animal10.animalAttr[12] = 3;
    animal11.animalAttr[12] = 3;
    animal12.animalAttr[12] = 2;
    animal13.animalAttr[12] = 3;
    animal14.animalAttr[12] = 3;
    animal15.animalAttr[12] = 3;
    animal16.animalAttr[12] = 2;
    animal17.animalAttr[12] = 3;
    animal18.animalAttr[12] = 2;
    animal19.animalAttr[12] = 3;
    animal20.animalAttr[12] = 1;
    animal21.animalAttr[12] = 1;
    animal22.animalAttr[12] = 1;
    animal23.animalAttr[12] = 2;
    animal24.animalAttr[12] = 1;
    animal25.animalAttr[12] = 1;


    // Neatness 1 is filthy 2 is average 3 is very clean
    animal1.animalAttr[13] = 1;
    animal2.animalAttr[13] = 2;
    animal3.animalAttr[13] = 3;
    animal4.animalAttr[13] = 3;
    animal5.animalAttr[13] = 2;
    animal6.animalAttr[13] = 3;
    animal7.animalAttr[13] = 3;
    animal8.animalAttr[13] = 1;
    animal9.animalAttr[13] = 1;
    animal10.animalAttr[13] = 3;
    animal11.animalAttr[13] = 3;
    animal12.animalAttr[13] = 2;
    animal13.animalAttr[13] = 3;
    animal14.animalAttr[13] = 3;
    animal15.animalAttr[13] = 3;
    animal16.animalAttr[13] = 2;
    animal17.animalAttr[13] = 3;
    animal18.animalAttr[13] = 2;
    animal19.animalAttr[13] = 3;
    animal20.animalAttr[13] = 1;
    animal21.animalAttr[13] = 1;
    animal22.animalAttr[13] = 1;
    animal23.animalAttr[13] = 2;
    animal24.animalAttr[13] = 1;
    animal25.animalAttr[13] = 1;

    //Current health 1 is currently fighting diesease 2 is weakened immune 3 is healthy
    animal1.animalAttr[14] = 1;
    animal2.animalAttr[14] = 1;
    animal3.animalAttr[14] = 2;
    animal4.animalAttr[14] = 3;
    animal5.animalAttr[14] = 3;
    animal6.animalAttr[14] = 3;
    animal7.animalAttr[14] = 1;
    animal8.animalAttr[14] = 1;
    animal9.animalAttr[14] = 2;
    animal10.animalAttr[14] = 2;
    animal11.animalAttr[14] = 2;
    animal12.animalAttr[14] = 2;
    animal13.animalAttr[14] = 2;
    animal14.animalAttr[14] = 1;
    animal15.animalAttr[14] = 2;
    animal16.animalAttr[14] = 2;
    animal17.animalAttr[14] = 1;
    animal18.animalAttr[14] = 2;
    animal19.animalAttr[14] = 3;
    animal20.animalAttr[14] = 3;
    animal21.animalAttr[14] = 3;
    animal22.animalAttr[14] = 1;
    animal23.animalAttr[14] = 1;
    animal24.animalAttr[14] = 1;
    animal25.animalAttr[14] = 2;


    // Intelligence Level 1 is stupid 2 average 3 is exceptional
    animal1.animalAttr[15] = 1;
    animal2.animalAttr[15] = 2;
    animal3.animalAttr[15] = 2;
    animal4.animalAttr[15] = 2;
    animal5.animalAttr[15] = 1;
    animal6.animalAttr[15] = 1;
    animal7.animalAttr[15] = 2;
    animal8.animalAttr[15] = 2;
    animal9.animalAttr[15] = 2;
    animal10.animalAttr[15] = 3;
    animal11.animalAttr[15] = 2;
    animal12.animalAttr[15] = 2;
    animal13.animalAttr[15] = 2;
    animal14.animalAttr[15] = 3;
    animal15.animalAttr[15] = 1;
    animal16.animalAttr[15] = 1;
    animal17.animalAttr[15] = 1;
    animal18.animalAttr[15] = 1;
    animal19.animalAttr[15] = 3;
    animal20.animalAttr[15] = 2;
    animal21.animalAttr[15] = 2;
    animal22.animalAttr[15] = 2;
    animal23.animalAttr[15] = 2;
    animal24.animalAttr[15] = 3;
    animal25.animalAttr[15] = 2;

    // Difficulty to train 1 is defiant 2 is chllenging 3 is easy
    animal1.animalAttr[16] = 1;
    animal2.animalAttr[16] = 1;
    animal3.animalAttr[16] = 2;
    animal4.animalAttr[16] = 2;
    animal5.animalAttr[16] = 2;
    animal6.animalAttr[16] = 3;
    animal7.animalAttr[16] = 3;
    animal8.animalAttr[16] = 3;
    animal9.animalAttr[16] = 3;
    animal10.animalAttr[16] = 3;
    animal11.animalAttr[16] = 2;
    animal12.animalAttr[16] = 2;
    animal13.animalAttr[16] = 3;
    animal14.animalAttr[16] = 3;
    animal15.animalAttr[16] = 3;
    animal16.animalAttr[16] = 1;
    animal17.animalAttr[16] = 1;
    animal18.animalAttr[16] = 1;
    animal19.animalAttr[16] = 1;
    animal20.animalAttr[16] = 1;
    animal21.animalAttr[16] = 2;
    animal22.animalAttr[16] = 2;
    animal23.animalAttr[16] = 2;
    animal24.animalAttr[16] = 3;
    animal25.animalAttr[16] = 3;

    // feeding cost 1 is expensive 2 is moderate 3 is cheap
    animal1.animalAttr[17] = 1;
    animal2.animalAttr[17] = 2;
    animal3.animalAttr[17] = 1;
    animal4.animalAttr[17] = 3;
    animal5.animalAttr[17] = 3;
    animal6.animalAttr[17] = 2;
    animal7.animalAttr[17] = 2;
    animal8.animalAttr[17] = 2;
    animal9.animalAttr[17] = 2;
    animal10.animalAttr[17] = 2;
    animal11.animalAttr[17] = 2;
    animal12.animalAttr[17] = 2;
    animal13.animalAttr[17] = 2;
    animal14.animalAttr[17] = 1;
    animal15.animalAttr[17] = 1;
    animal16.animalAttr[17] = 1;
    animal17.animalAttr[17] = 1;
    animal18.animalAttr[17] = 1;
    animal19.animalAttr[17] = 1;
    animal20.animalAttr[17] = 2;
    animal21.animalAttr[17] = 2;
    animal22.animalAttr[17] = 1;
    animal23.animalAttr[17] = 2;
    animal24.animalAttr[17] = 3;
    animal25.animalAttr[17] = 4;


    // noise level 1 is noisy 2 is moderate 3 is quiet
    animal1.animalAttr[18] = 1;
    animal2.animalAttr[18] = 2;
    animal3.animalAttr[18] = 3;
    animal4.animalAttr[18] = 3;
    animal5.animalAttr[18] = 2;
    animal6.animalAttr[18] = 3;
    animal7.animalAttr[18] = 3;
    animal8.animalAttr[18] = 1;
    animal9.animalAttr[18] = 1;
    animal10.animalAttr[18] = 3;
    animal11.animalAttr[18] = 3;
    animal12.animalAttr[18] = 2;
    animal13.animalAttr[18] = 3;
    animal14.animalAttr[18] = 3;
    animal15.animalAttr[18] = 3;
    animal16.animalAttr[18] = 2;
    animal17.animalAttr[18] = 3;
    animal18.animalAttr[18] = 2;
    animal19.animalAttr[18] = 3;
    animal20.animalAttr[18] = 1;
    animal21.animalAttr[18] = 1;
    animal22.animalAttr[18] = 1;
    animal23.animalAttr[18] = 2;
    animal24.animalAttr[18] = 1;
    animal25.animalAttr[18] = 1;

qDebug("Tryunna add");
    this->pushAnimal(animal1);
    this->pushAnimal(animal2);
    this->pushAnimal(animal3);
    this->pushAnimal(animal4);
    this->pushAnimal(animal5);
    this->pushAnimal(animal6);
    this->pushAnimal(animal7);
    this->pushAnimal(animal8);
    this->pushAnimal(animal9);
    this->pushAnimal(animal10);
    this->pushAnimal(animal11);
    this->pushAnimal(animal12);
    this->pushAnimal(animal13);
    this->pushAnimal(animal14);
    this->pushAnimal(animal15);
    this->pushAnimal(animal16);
    this->pushAnimal(animal17);
    this->pushAnimal(animal18);
    this->pushAnimal(animal19);
    this->pushAnimal(animal20);
    this->pushAnimal(animal21);
    this->pushAnimal(animal22);
    this->pushAnimal(animal23);
    this->pushAnimal(animal24);
    this->pushAnimal(animal25);
    this->pushClient(client1);
    this->pushClient(client2);
    this->pushClient(client3);
    this->pushClient(client4);
    this->pushClient(client5);


    return(0);
}
