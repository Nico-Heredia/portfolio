public class Paciente {
    private String nombre;
    private int edad;
    private Double telefono;
    private Double dni;
    private String mail;
    private String diagnostico;

    // Constructor
    public Paciente(String nombre, int edad, Double telefono, Double dni, String mail, String diagnostico) {
        this.nombre = nombre;
        this.edad = edad;
        this.telefono = telefono;
        this.dni = dni;
        this.mail = mail;
        this.diagnostico = diagnostico;
    }

    // Get y set
    public String getNombre() { return nombre; }
    public void setNombre(String nombre) { this.nombre = nombre; }
    public int getEdad() { return edad; }
    public void setEdad(int edad) { this.edad = edad; }
    public Double getTelefono() { return telefono; }
    public void setTelefono(Double telefono) { this.telefono = telefono; }
    public Double getDni() { return dni; }
    public void setDni(Double dni) { this.dni = dni; }
    public String getMail() { return mail; }
    public void setMail(String mail) { this.mail = mail; }
    public String getDiagnostico() { return diagnostico; }
    public void setDiagnostico(String diagnostico) { this.diagnostico = diagnostico; }

    @Override
    public String toString() {
        return "Paciente{" +
                "Nombre='" + nombre + '\'' +
                ", Edad=" + edad +
                ", Teléfono=" + telefono +
                ", DNI=" + dni +
                ", Email='" + mail + '\'' +
                ", Diagnóstico='" + diagnostico + '\'' +
                '}';
    }
}
