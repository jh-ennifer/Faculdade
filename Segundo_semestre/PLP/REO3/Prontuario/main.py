from paciente import Paciente
from medico import Medico
from medicamento import Medicamento
from prontuario import Prontuario

paciente1 = Paciente('Paciente1')
prontuario1 = Prontuario()
paciente2 = Paciente('Paciente2')
prontuario2 = Prontuario()
medicamento1 = Medicamento('Omeprazol')
medicamento2 = Medicamento('Tylenol')
medicamento3 = Medicamento('Dipirona')
medico1 = Medico('Medico1')
medico2 = Medico('Medico2')
paciente1.definir_prontuario(prontuario1)
paciente2.definir_prontuario(prontuario2)
paciente1.prontuario.insere_procedimento(medicamento1, '68mcg',
medico1, "15-06-2020", "10:10")
paciente1.prontuario.insere_procedimento(medicamento2, '100mg',
medico1, "15-06-2020", "11:40")
paciente2.prontuario.insere_procedimento(medicamento2, '18mcg',
medico2, "14-06-2020", "12:00")
paciente2.prontuario.insere_procedimento(medicamento3, '20mg',
medico2, "15-06-2020", "12:05")

paciente1.prontuario.exibe_prontuario()
paciente2.prontuario.exibe_prontuario()
print(Paciente.pacientes_ativos())
del paciente2
print(Paciente.pacientes_ativos())
