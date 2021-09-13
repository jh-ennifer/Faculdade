from medicamento import Medicamento
from medico import Medico


class Prontuario(object):
    def __init__(self):
        self.__registros = []

    def insere_procedimento(self, medicamento: Medicamento, posologia: str, medico: Medico, data: str, hora: str):
        procedimento = {
            "medicamento": medicamento.nome_medicamento(),
            "posologia": posologia,
            "medico": medico.nome_medico(),
            "data": data,
            "hora": hora
        }

        self.__registros.append(procedimento)

    def exibe_prontuario(self):
        for procedimento in self.__registros:
            print(f'{procedimento["medicamento"]} - {procedimento["posologia"]} - {procedimento["medico"]} - {procedimento["data"]} - {procedimento["hora"]}')
            