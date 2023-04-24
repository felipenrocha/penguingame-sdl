//
// Created by edgar on 23/03/18.
//

#include <algorithm>
#include "../include/GameObject.h"

GameObject::GameObject() {
    //Inicializa isDead com falso.
    isDead = false;
}

GameObject::~GameObject() {
    // free all components
    /* Percorre vetor de components dando delete em todos e depois dando
        clear no vetor.Dica: Percorra o vetor de trás para frente e chame delete
        usando o iterador do começo mais o index atual.*/

    for (auto it = components.rbegin(); it != components.rend(); ++it) {
        RemoveComponent(*it);
    }
}

void GameObject::Update(float dt) {
    for (auto it = components.begin(); it != components.end(); ++it) {
        (*it)->Update(dt);
    }
}

void GameObject::Render() {
    /* Percorre o vetor de componentes chamando o Update(dt) dos
       mesmos. */
    for (auto it = components.begin(); it != components.end(); ++it) {
        (*it)->Render();
    }
}

bool GameObject::IsDead() {
    //Retorna isDead.
    return isDead;
}

void GameObject::RequestDelete() {
    //Atribui verdadeiro a isDead
    isDead = true;
}

void GameObject::AddComponent(Component* cpt) {
    // Adiciona o componente ao vetor de componentes
    components.push_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt) {
    //Remove o componente do vetor de componentes, isto é, se ele estiver lá.
    components.erase(std::remove(components.begin(), components.end(), cpt));
}

Component* GameObject::GetComponent(string type) {
    /*Retorna um ponteiro para o componente do tipo solicitado que estiver
    adicionado nesse objeto. nullptr caso esse componente não exista.
    */
    for (auto it = components.begin(); it != components.end(); ++it) {
        if ((*it)->Is(type)) {
            return *it;
        }
    }
    return nullptr;
}
