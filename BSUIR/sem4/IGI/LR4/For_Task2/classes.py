class MixIn:
    """Example mixin providing utility method."""
    def greet(self):
        return f"Hello from {self.__class__.__name__}"  # dynamic attribute usage

class BaseAnalyzer(MixIn):
    """Polymorphic base class for analyzers."""
    static_attr = "Analyzer v1"

    def __init__(self, text):
        self._text = text  # dynamic attribute

    @property
    def text(self):
        """Get the raw text."""
        return self._text

    @text.setter
    def text(self, value):
        """Set new text."""
        self._text = value

    def analyze(self):
        """Override in subclasses."""
        raise NotImplementedError