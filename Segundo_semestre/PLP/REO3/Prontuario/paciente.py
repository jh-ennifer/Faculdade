from pessoa import Pessoa
from prontuario import Prontuario


class Paciente(Pessoa):
    count = 0

    def __init__(self, nome):
        Pessoa.__init__(self, nome)
        Paciente.count += 1

    def __del__(self):
        Paciente.count -= 1

    def definir_id(self, id: int):
        if id > 99999:
            print('Erro')

    def definir_prontuario(self, prontuario: Prontuario):
        self.prontuario = prontuario

    @classmethod
    def pacientes_ativos(self):
        return Paciente.count
