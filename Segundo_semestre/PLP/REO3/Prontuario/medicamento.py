class Medicamento(object):
    def __init__(self, nome):
        self.__nome = nome

    def nome_medicamento(self):
        return self.__nome