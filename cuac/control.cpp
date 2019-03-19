#include "control.h"
#include "homeview.h"




Control::Control(){

    animals = new Array<Animal>();
    clients = new Array<Client>();
    db = new Database();
    db->initTables();
    db->initValues();
    qDebug("ANIMAL SIZE: %d", animals->getSize());
}

void Control::addAnimal(Animal* a){
    animals->add(a);

    AnimalData newAnimal;
    newAnimal.animalName = a->getName();
    newAnimal.typeOfAnimal = a->getSpecies();
    newAnimal.breed = a->getBreed();
    newAnimal.animalAttr[0] = 0;
    newAnimal.animalAttr[1] = a->getAge();
    newAnimal.animalAttr[2] = a->getWeight();
    newAnimal.animalAttr[3] = a->getHeight();
    newAnimal.animalAttr[4] = a->getEnergy_level();
    newAnimal.animalAttr[5] = a->getTemperament();
    newAnimal.animalAttr[6] = a->getKid_friendly();
    newAnimal.animalAttr[7] = a->getBad_habits();
    newAnimal.animalAttr[8] = a->getLevel_of_care();
    newAnimal.animalAttr[9] = a->getLevel_of_dependency();
    newAnimal.animalAttr[10] = a->getProne_to_disease();
    newAnimal.animalAttr[11] = a->getLiving_space();
    newAnimal.animalAttr[12] = a->getClimate();
    newAnimal.animalAttr[14] = a->getNeatness();
    newAnimal.animalAttr[15] = a->getCurrent_health_condition();
    newAnimal.animalAttr[16] = a->getIntelligence_level();
    newAnimal.animalAttr[17] = a->getDifficulty_to_train();
    newAnimal.animalAttr[18] = a->getFeeding_cost();
    newAnimal.animalAttr[19] = a->getNoise_level();

    if (db->pushAnimal(newAnimal)) qDebug("failed to push animal to db");
}

void Control::addClient(Client* c){

    clients->add(c);

    ClientData newClient;

    newClient.clientName = c->getName();
    newClient.clientEmail = c->getEmail();
    newClient.clientAddr = c->getAddress();
    newClient.species = "";
    newClient.breed = "";
    newClient.clientAttr[0] = c->getHomePhone();
    newClient.clientAttr[1] = c->getCellPhone();
    newClient.clientAttr[2] = c->getAge();
    newClient.clientAttr[3] = c->getGender();

    if (db->pushClient(newClient)) qDebug("failed to push animal to db");
}

void Control::updateAnimal(Animal* a){
    
}
void Control::upDateClient(Client* c){}

Animal* Control::getAnimal(int index){return animals->get(index);}

Client* Control::getClient(int index){return clients->get(index);}


void Control:: populateAnimalArray(){


    AnimalData** aLists = db->pullAnimals();
    int x = 0;
    while(aLists[x] != NULL){

        Animal *a = new Animal(aLists[x]->animalName,
                               aLists[x]->typeOfAnimal,
                               aLists[x]->breed,
                               aLists[x]->animalAttr[1],
                               aLists[x]->animalAttr[2],
                               aLists[x]->animalAttr[3],
                               aLists[x]->colour,
                               /*aLists[x]->specialSkill*/ 0,
                               aLists[x]->animalAttr[4],
                               aLists[x]->animalAttr[6],
                               aLists[x]->animalAttr[9],
                               aLists[x]->animalAttr[10],
                               aLists[x]->animalAttr[11],
                               aLists[x]->animalAttr[18],
                               aLists[x]->animalAttr[12],
                               aLists[x]->animalAttr[8],
                               aLists[x]->animalAttr[14],
                               aLists[x]->animalAttr[15],
                               aLists[x]->animalAttr[16],
                               aLists[x]->animalAttr[17],
                               aLists[x]->animalAttr[19],
                               aLists[x]->animalAttr[5],
                               aLists[x]->animalAttr[7]);


        animals->add(a);
        x++;
    }
}

void Control:: populateClientArray(){


    ClientData** cLists = db->pullClients();

    int x = 0;
    while(cLists[x] != NULL){

        Client *c = new Client(cLists[x]->clientName, cLists[x]->clientEmail,
                               cLists[x]->clientAddr, cLists[x]->clientAttr[2],
                              cLists[x]->clientAttr[3], cLists[x]->clientAttr[1],
                              cLists[x]->clientAttr[0],
                cLists[x]->clientAttr[4],
                cLists[x]->clientAttr[5],
                cLists[x]->clientAttr[6],
                cLists[x]->clientAttr[7],
                cLists[x]->clientAttr[8],
                cLists[x]->clientAttr[9],
                cLists[x]->clientAttr[10],
                cLists[x]->species,
                cLists[x]->breed,
                cLists[x]->clientAttr[18],
                cLists[x]->clientId);

        clients->add(c);
        x++;
    }
}

int Control::getAnimalArraySize(){return animals->getSize();}
int Control::getClientArraySize(){return clients->getSize();}

void Control::setHomeView(HomeView* h){
    home = h;
    home->control = this;
}

HomeView* Control::getHomeView(){return home;}
