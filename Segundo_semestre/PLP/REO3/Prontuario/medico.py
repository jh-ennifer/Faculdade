from pessoa import Pessoa


class Medico(Pessoa):
    def __init__(self, nome):
        Pessoa.__init__(self, nome)
        self.__nome = nome

    def definir_id(self, id: int):
        if id > 999:
            print('Erro')

    def nome_medico(self):
        return self.__nome