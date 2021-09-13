import abc


class Pessoa(abc.ABC):
    def __init__(self, nome):
        self.__nome = nome

    def getNome(self):
        return self.__nome

    @abc.abstractmethod
    def definir_id(self, id):
        pass
