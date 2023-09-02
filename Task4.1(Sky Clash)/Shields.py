class Shield:
    def __init__(self, save, energy, resources):
        self.save = save
        self.energy = energy
        self.remaining_uses = resources

    def defend(self, damage):
        return damage*(1 - self.save)

class GruShield(Shield):
    pass

class VectorShield(Shield):
    pass

class EnergyProjectedBarrierGun(GruShield):
    def __init__(self):
        super().__init__(save=0.4, energy=20, resources=float('inf'))

class SelectivePermeability(GruShield):
    def __init__(self):
        super().__init__(save=0.9, energy=50, resources=2)

class EnergyNetTrap(VectorShield):
    def __init__(self):
        super().__init__(save=0.32, energy=15, resources=float('inf'))

class QuantumDeflector(VectorShield):
    def __init__(self):
        super().__init__(save=0.8, energy=40, resources=3)
