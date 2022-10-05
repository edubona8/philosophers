# Philosophers

- Este projeto é sobre os conceitos básicos de criação de threads. Como evitar race conditions e deadlocks.

## Sumary

#### Como desenvolveremos essa aplicação?
- Utilizaremos o método de aprendizagem `coding dojo`. Coding Dojo é um método de aprendizagem para desenvolvimento de projetos em computação, é uma reunião entre várias pessoas que desejam trabalhar coletivamente em um desafio de programação. O desafio pode ser um problema algorítmico a ser resolvido ou uma necessidade de implementação.
- Trabalharemos com sessões de 42 minutos, com break de 10 minutos. 
- Segue o timer que utilizamos:
```
https://cuckoo.team/feynman
```

#### O desafio dos filósofos
- O problema consiste em x filósofos sentados ao redor de uma mesa de jantar circular, onde cada filósofo tem um prato para comer espaguete e um garfo à sua direita. Para comer, eles precisam de 2 garfos, mas há apenas um garfo entre cada par de pratos. Um filósofo tem três ações: comer, pensar ou dormir. Quando um filósofo fica com fome, ele tentará pegar o garfo à direita e à esquerda, um de cada vez. Se ele conseguir pegar os dois garfos, ele comerá a comida em um determinado momento e colocará os garfos na mesa, vai dormir e depois vai pensar novamente.
