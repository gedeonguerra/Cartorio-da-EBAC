Projeto do curso de TI "TI do Zero ao Pro"

# Cartório da EBAC

Um sistema simples em linguagem C para cadastro, consulta e exclusão de usuários utilizando CPF como identificador.

---

## :computer: Funcionalidades

- Cadastro de usuário (CPF, nome, sobrenome, cargo)
- Consulta de usuário por CPF
- Exclusão de usuário (remove arquivo baseado no CPF)
- Interface de menu simples no terminal

---

## :gear: Requisitos

- Sistema Operacional: Windows (usa `system("cls")` e `system("pause")`)
- Compilador C (como GCC via MinGW)

---

## :rocket: Como compilar

Se estiver usando o GCC no terminal (cmd ou PowerShell no Windows):

```bash
gcc cartorio.c -o cartorio.exe
```

> Substitua `cartorio.c` pelo nome do seu arquivo, caso seja diferente.

---

## :keyboard: Como executar

Após a compilação, execute o programa:

```bash
cartorio.exe
```

> O programa abrirá um menu no terminal com as opções:

```
### Cartório da EBAC ###

Escolha a opção desejada no menu:
	1 - Registrar usuário
	2 - Consultar usuário
	3 - Deletar usuário
	4 - Sair do sistema
```

---

## :floppy_disk: Como os dados são armazenados?

Cada usuário é salvo em um arquivo separado com o nome baseado no CPF.
O conteúdo do arquivo segue o formato:

```
CPF,NOME,SOBRENOME,CARGO
```

Por exemplo:
```
12345678900,Ana,Silva,Analista
```

---

## :warning: Observações importantes

- O CPF é usado como nome do arquivo, então ele deve ser único.
- Os dados não são criptografados nem validados.
- Uso exclusivo para fins didáticos.

---

## :pencil: Melhorias sugeridas

- Validar o formato do CPF
- Suporte para sobrenomes e cargos com espaços
- Salvar os dados em um arquivo .csv único
- Implementar versão multiplataforma (Linux/macOS)

---

## :page_facing_up: Licença

Projeto educacional desenvolvido para fins de aprendizado na EBAC.

---

Feito com :heart: para estudo.

## senha padrão para usar o App "admin"

---

# :clipboard: Relatório de Casos de Teste

## :lock: Login

- ✅ Acesso do administrador funcionou corretamente.
- ✅ Tentativas de acesso com senhas incorretas foram devidamente recusadas.

## :gear: Menu Principal

- ✅ Menu criado corretamente: a instância foi iniciada e encerrada conforme esperado.
- ✅ Todas as funções foram chamadas corretamente:
  - Inserir
  - Consultar
  - Deletar

## :inbox_tray: Função Inserir

- ✅ Banco de dados criado corretamente.
- ✅ Inserção de dados realizada com sucesso:
  - CPF
  - Nome
  - Sobrenome
  - Cargo
- ✅ Encerramento da função e retorno ao menu confirmados.

## :mag_right: Função Consultar

- ✅ Solicitação de CPF executada corretamente.
- ✅ Consulta realizada com sucesso.
- ✅ Dados retornados corretamente ao usuário.
- ✅ Retorno ao menu efetuado.

## :wastebasket: Função Deletar

- ✅ Solicitação de CPF aceita corretamente.
- ✅ Exclusão do arquivo correspondente realizada com sucesso.

---

## :bulb: Princípios Mantidos

- Inserção de dados
- Atualização de dados (regravação sobre o mesmo CPF)
- Exclusão de dados

---

## :white_check_mark: Conclusão

O produto está **100% funcional** e pronto para consumo do usuário final. Todos os testes executados foram concluídos com sucesso. 

> Sistema validado com base nas funcionalidades esperadas e comportamentos previstos.

