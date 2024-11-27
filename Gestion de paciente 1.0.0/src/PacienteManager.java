import java.util.ArrayList;
import java.util.List;

public class PacienteManager {
    private List<Paciente> pacientes;

    public PacienteManager() {
        this.pacientes = new ArrayList<>();
    }

    public void agregarPaciente(Paciente paciente) {
        pacientes.add(paciente);
    }

    public List<Paciente> listarPacientes() {
        return pacientes;
    }

    public Paciente buscarPaciente(String nombre) {
        for (Paciente p : pacientes) {
            if (p.getNombre().equalsIgnoreCase(nombre)) {
                return p;
            }
        }
        return null;
    }
}

